/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2018 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/*
THERE IS A BUG, if you change the chordType while still playing one some notes will not receive noteOFF
*/
#include "DistrhoPlugin.hpp"
#include "chords.hpp"
#include <stdio.h>
START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class GuitarChords : public Plugin
{
public:
    GuitarChords()
        : Plugin(1, 0, 0) {} //one parameter, one program
        
         
protected:
   /* --------------------------------------------------------------------------------------------------------
    * Information */

   /**
      Get the plugin label.
      This label is a short restricted name consisting of only _, a-z, A-Z and 0-9 characters.
    */
    const char* getLabel() const override
    {
        return "GuitarChords";
    }

   /**
      Get an extensive comment/description about the plugin.
    */
    const char* getDescription() const override
    {
        return " A 'real' midi guitar chord generator. Different octaves will send different positions of the same chord and a second note played on top of the root will tell the chord type(Maj-Min...)";
    }

   /**
      Get the plugin author/maker.
    */
    const char* getMaker() const override
    {
        return "Haradai";
    }

   /**
      Get the plugin homepage.
    */
    const char* getHomePage() const override
    {
        return "";
    }

   /**
      Get the plugin license name (a single line of text).
      For commercial plugins this should return some short copyright information.
    */
    const char* getLicense() const override
    {
        return "ISC";
    }

   /**
      Get the plugin version, in hexadecimal.
    */
    uint32_t getVersion() const override
    {
        return d_version(1, 0, 0);
    }

   /**
      Get the plugin unique Id.
      This value is used by LADSPA, DSSI and VST plugin formats.
    */
    int64_t getUniqueId() const override
    {
        return d_cconst('d', 'M', 'T', 'r');
    }

   /* --------------------------------------------------------------------------------------------------------
    * Init and Internal data, unused in this plugin */

    void  initParameter(uint32_t index, Parameter& parameter) override {
        switch(index){
            case 0:
                parameter.hints = kParameterIsAutomable|kParameterIsBoolean;
                parameter.ranges.min = 0.0;
                parameter.ranges.max = 1.0;
                parameter.ranges.def = 0.0;
                parameter.name = "Strum Speed";
                parameter.symbol = "STRUM";
                break;
        }
    }
    float getParameterValue(uint32_t index) const   override { 
        switch(index){
            case 0:
                return StrSpeed;
                break;
        }
        return 0;
    }
    void  setParameterValue(uint32_t index, float value)  override {
        switch(index){
            case 0:
                StrSpeed = value;
                break;
        }
    }

   /* --------------------------------------------------------------------------------------------------------
    * Audio/MIDI Processing */ 

   /**
      Run/process function for plugins with MIDI input.
      In this case we just pass-through all MIDI events.
    */
    void run(const float**, float**, uint32_t,
             const MidiEvent* midiEvents, uint32_t midiEventCount) override
    {   
        if (init == false)
        { //init function
            rootNote.data[1] = 127;
            chordNote.data[1] = 127;
            init = true;
        }
        
        if(midiEventCount > 0 )
        {
            //see if rootNote or chordNote are being turned OFF
            for (uint8_t i = 0; i < midiEventCount; i++)
            {
                if (midiEvents[i].data[1] == rootNote.data[1] && midiEvents[i].data[0] >= 0x80 && midiEvents[i].data[0] <= 0x8F)
                {
                    rootNote.data[1] = 127; //this is so any consequent input note can be detected as new root
                    stopChord();
                }  

                if (midiEvents[i].data[1] == chordNote.data[1] && midiEvents[i].data[0] >= 0x80 && midiEvents[i].data[0] <= 0x8F)
                {
                    chordNote = rootNote;
                    stopChord();
                } 
            }

            //Now detect the new chord to play if any 
            //find lowest note
            for (uint8_t i = 0; i < midiEventCount; i++)
            {
                if(midiEvents[i].data[1] < rootNote.data[1] && midiEvents[i].data[0] >= 0x90 && midiEvents[i].data[0] <= 0x9F)
                {
                    rootNote = midiEvents[i];
                    stopChord();
                }
            }

            //find consecutive note (to rootNote) that will decice chord type
            for (uint8_t i = 0; i < midiEventCount; i++)
            {
                if(midiEvents[i].data[1] >= rootNote.data[1] && midiEvents[i].data[0] >= 0x90 && midiEvents[i].data[0] <= 0x9F)
                {
                        chordNote = midiEvents[i];
                        stopChord();
                }
            }

            if(rootNote.data[0] >= 0x90 && rootNote.data[0] <= 0x9F)
            {
                makeChord(chord,rootNote,chordNote.data[1] - rootNote.data[1]);
                //adjust for string tuning


                for (uint8_t i = 0; i < 6; i++) //play the chord
                {
                    writeMidiEvent(chord[i]);
                }
            }
            //printf("\nrootnote: %d ,chordnote: %d",rootNote.data[1],chordNote.data[1]);
        }
        else if(stpchord == true){
             for (uint8_t i = 0; i < 6; i++) //turn off any chord playing
            {
                writeMidiEvent(chord[i]);
            }
            stpchord = false;
        }
    }


void stopChord(){
    for (uint8_t i = 0; i < 6; i++) //turn off any chord playing
    {
        chord[i].data[0] = 0x80;
    }
    stpchord = true;

}
private:

    MidiEvent chorda[6];  
    MidiEvent *chord = chorda;

    MidiEvent rootNote;
    MidiEvent chordNote; 

    
    
    //It seems I cannot do this, so I create an extra variable as a startup function
    //rootNote.data[0] = 0x80;
    bool init = false;

    bool stpchord = false;
    int dist; //distance from root to "type of chord deciding note"
    int oct; //octave of root note
    float StrSpeed = 0.0;
    
   /**
      Set our plugin class as non-copyable and add a leak detector just in case.
    */
    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GuitarChords)
};

/* ------------------------------------------------------------------------------------------------------------
 * Plugin entry point, called by DPF to create a new plugin instance. */

Plugin* createPlugin()
{
    return new GuitarChords();
}

// -----------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO