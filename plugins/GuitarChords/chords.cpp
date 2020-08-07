#include "DistrhoPlugin.hpp"
#include "chords.hpp"
#include <stdio.h>

/* We define these here so they don't have to be included every time we call a chord function*/
MidiEvent *CHORD;
MidiEvent ROOTnOTE;
int OCT;
/**/

/*Functions*/
void minor3_1();
void major3_1();
void major7_1();
void minor7_1();
void sept_dom_1();
void dim3_1();
void aug3_1();
void maj6_1();
void min6_1();
void sus2_1();
void sus4_1();
void min9_1();
void maj9_1();

void makeChord(MidiEvent *chord , MidiEvent rootNote , int dist)
{   
    CHORD = chord;
    ROOTnOTE = rootNote;
    OCT = rootNote.data[1]/12; //-2 Really depends on when u start to count octave -2 or 0 or -1 ...
    //printf("\n oct: %d, dist: %d",OCT,dist);

    for (int i = 0; i < 6; i++)
    {
        CHORD[i].data[0] = 0x90;
        CHORD[i].data[2] = ROOTnOTE.data[2];
        CHORD[i].frame = 0;
        CHORD[i].size = 3;
    }

    switch (dist)
    {
    case 1:
        switch (OCT)
        {
        case 1:
            minor3_1();
            break;
        //here add more and more 
        default:
            minor3_1();
            break;
        }   
        break;

    case 2:
        switch (OCT)
        {
        case 1:
            minor7_1();
            break;
        //here add more and more 
        default:
            major3_1();
            break;
        }
        break;

    case 3:
        switch (OCT)
        {
        case 1:
            min6_1();
            break;
    
        default:
            min6_1();
            break;
         }
        break;
    
     case 4:
        switch (OCT)
        {
        case 1:
            dim3_1();
            break;
        
        default:
            dim3_1();
            break;
        }
        break;

    case 5:
        switch (OCT)
        {
        case 1:
            major3_1();
            break;
        
        default:
            major3_1();
            break;
        }
        break;

    case 6:
        switch (OCT)
        {
        case 1:
            major7_1();
            break;
        
        default:
            major3_1();
            break;
        }
        break;

    case 7:
        switch (OCT)
        {
        case 1:
            maj6_1();
            break;
        
        default:
            maj6_1();
            break;
        }
        break;
    
    case 8:
        switch (OCT)
        {
        case 1:
            aug3_1();
            break;
        
        default:
            aug3_1();
            break;
        }
        break;

    case 9:
        switch (OCT)
        {
        case 1:
            sept_dom_1();
            break;
        
        default:
            sept_dom_1();
            break;
        }
        break;

    case 10:
        switch (OCT)
        {
        case 1:
            sus2_1();
            break;
        
        default:
            sus2_1();
            break;
        }
        break;

    case 11:
        switch (OCT)
        {
        case 1:
            sus4_1();
            break;
        
        default:
            sus4_1();
            break;
        }
        break;

    case 12:
        switch (OCT)
        {
        case 1:
            min9_1();
            break;
        
        default:
            min9_1();
            break;
        }
        break;
    
     case 13:
        switch (OCT)
        {
        case 1:
            maj9_1();
            break;
        
        default:
            maj9_1();
            break;
        }
        break;



    default:
        break;
    } 
}



/*CHORDS*/
void minor3_1() 
{
    switch (ROOTnOTE.data[1]-(12*OCT))
    { //Here I found a pattern so I'm just gonna calculate everything
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 3;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 6;
        CHORD[4].data[1] = 5;
        CHORD[5].data[1] = 4;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127;
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 1;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127;
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 2;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 0; 
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 0;
        break;
    
    case 5: //Fa (F)
        CHORD[1].data[1] = 1; 
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 1;
        break;
    
    case 6: //Fa# (F#)
        CHORD[1].data[1] = 2; 
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 2;
        break;
    
    case 7: //Sol (G)
        CHORD[1].data[1] = 3; 
        CHORD[1].data[1] = 5; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 3;
        break;

    case 8: //Sol# (G#)
        CHORD[1].data[1] = 4; 
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 4;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 0;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 1;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 2;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}



void major3_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    { //Here I found a pattern so I'm just gonna calculate everything
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 0;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 1;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; 
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 2;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127;
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 3;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 0; 
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 0;
        break;
    
    case 5: //Fa (F)
        CHORD[1].data[1] = 1; 
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 1;
        break;
    
    case 6: //Fa# (F#)
        CHORD[1].data[1] = 2; 
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 2;
        break;
    
    case 7: //Sol (G)
        CHORD[1].data[1] = 3; 
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 3;
        break;

    case 8: //Sol# (G#)
        CHORD[1].data[1] = 4; 
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 4;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 0;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 1;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 2;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void sept_dom_1() 
{
    switch (ROOTnOTE.data[1]-(12*OCT))
    { //Here I found a pattern so I'm just gonna calculate everything
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 127;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 127;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127;
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 2;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127;
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 3;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 0; 
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 0;
        break;
    
    case 5: //Fa (F)
        CHORD[1].data[1] = 1; 
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 1;
        break;
    
    case 6: //Fa# (F#)
        CHORD[1].data[1] = 2; 
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 2;
        break;
    
    case 7: //Sol (G)
        CHORD[1].data[1] = 3; 
        CHORD[1].data[1] = 5; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 3;
        break;

    case 8: //Sol# (G#)
        CHORD[1].data[1] = 4; 
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 4;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 0;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 1;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 127;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void minor7_1() 
{
    switch (ROOTnOTE.data[1]-(12*OCT))
    { //Here I found a pattern so I'm just gonna calculate everything
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 3;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 5;
        CHORD[5].data[1] = 4;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127;
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 1;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127;
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 2;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 0; 
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 0;
        break;
    
    case 5: //Fa (F)
        CHORD[1].data[1] = 1; 
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 1;
        break;
    
    case 6: //Fa# (F#)
        CHORD[1].data[1] = 2; 
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 2;
        break;
    
    case 7: //Sol (G)
        CHORD[1].data[1] = 3; 
        CHORD[1].data[1] = 5; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 3;
        break;

    case 8: //Sol# (G#)
        CHORD[1].data[1] = 4; 
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 4;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 0;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 1;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 2;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void major7_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    { //Here I found a pattern so I'm just gonna calculate everything
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 0;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 1;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; 
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 2;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127;
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 3;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 0; 
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 127;
        break;
    
    case 5: //Fa (F)
        CHORD[1].data[1] = 127; 
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 0;
        break;
    
    case 6: //Fa# (F#)
        CHORD[1].data[1] = 127; 
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 1;
        break;
    
    case 7: //Sol (G)
        CHORD[1].data[1] = 127; 
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 2;
        break;

    case 8: //Sol# (G#)
        CHORD[1].data[1] = 127; 
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 3;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 0;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 1;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 2;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void dim3_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    {
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 127;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 6;
        CHORD[4].data[1] = 5;
        CHORD[5].data[1] = 127;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 5; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 7;
        CHORD[4].data[1] = 6;
        CHORD[5].data[1] = 127;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 7;
        CHORD[3].data[1] = 8;
        CHORD[4].data[1] = 7;
        CHORD[5].data[1] = 127;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 7; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 8;
        CHORD[3].data[1] = 9;
        CHORD[4].data[1] = 8;
        CHORD[5].data[1] = 127;
        break;
    
    case 5: //Fa (F)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 8; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 9;
        CHORD[3].data[1] = 10;
        CHORD[4].data[1] = 9;
        CHORD[5].data[1] = 127;
        break;
    
    case 6: //Fa# (F#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 9; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 10;
        CHORD[3].data[1] = 11;
        CHORD[4].data[1] = 10;
        CHORD[5].data[1] = 127;
        break;
    
    case 7: //Sol (G)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 10; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 11;
        CHORD[3].data[1] = 12;
        CHORD[4].data[1] = 11;
        CHORD[5].data[1] = 127;
        break;

    case 8: //Sol# (G#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 11; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 12;
        CHORD[3].data[1] = 13;
        CHORD[4].data[1] = 12;
        CHORD[5].data[1] = 127;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 12; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 13;
        CHORD[3].data[1] = 14;
        CHORD[4].data[1] = 13;
        CHORD[5].data[1] = 127;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 13; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 14;
        CHORD[3].data[1] = 15;
        CHORD[4].data[1] = 14;
        CHORD[5].data[1] = 127;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 127;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void aug3_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    {
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 127;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 127;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 5;
        CHORD[5].data[1] = 127;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 6;
        CHORD[5].data[1] = 127;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 5; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 6;
        CHORD[4].data[1] = 7;
        CHORD[5].data[1] = 127;
        break;
    
    case 5: //Fa (F)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 7;
        CHORD[4].data[1] = 8;
        CHORD[5].data[1] = 127;
        break;
    
    case 6: //Fa# (F#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 7; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 7;
        CHORD[3].data[1] = 8;
        CHORD[4].data[1] = 9;
        CHORD[5].data[1] = 127;
        break;
    
    case 7: //Sol (G)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 8; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 8;
        CHORD[3].data[1] = 9;
        CHORD[4].data[1] = 10;
        CHORD[5].data[1] = 127;
        break;

    case 8: //Sol# (G#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 9; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 9;
        CHORD[3].data[1] = 10;
        CHORD[4].data[1] = 11;
        CHORD[5].data[1] = 127;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 10; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 10;
        CHORD[3].data[1] = 11;
        CHORD[4].data[1] = 12;
        CHORD[5].data[1] = 127;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 11; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 11;
        CHORD[3].data[1] = 12;
        CHORD[4].data[1] = 13;
        CHORD[5].data[1] = 127;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 12; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 12;
        CHORD[3].data[1] = 13;
        CHORD[4].data[1] = 14;
        CHORD[5].data[1] = 127;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void maj6_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    {
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 0;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 127;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 2;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 127;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 0; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 0;
        break;
    
    case 5: //Fa (F)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 1;
        break;
    
    case 6: //Fa# (F#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 2;
        break;
    
    case 7: //Sol (G)
        CHORD[0].data[1] = 3; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 0;
        break;

    case 8: //Sol# (G#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 6;
        CHORD[5].data[1] = 4;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 2;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 3;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 2; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 127;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void min6_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    {
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 3;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 6; //"do not play this string"
        CHORD[1].data[1] = 7; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 8;
        CHORD[3].data[1] = 6;
        CHORD[4].data[1] = 9;
        CHORD[5].data[1] = 6;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 1;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 2;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 0; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 0;
        break;
    
    case 5: //Fa (F)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 1;
        break;
    
    case 6: //Fa# (F#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 6;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 5;
        break;
    
    case 7: //Sol (G)
        CHORD[0].data[1] = 3; //"do not play this string"
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 0;
        break;

    case 8: //Sol# (G#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 8;
        CHORD[4].data[1] = 6;
        CHORD[5].data[1] = 7;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 2;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 6; //"do not play this string"
        CHORD[1].data[1] = 8; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 8;
        CHORD[3].data[1] = 6;
        CHORD[4].data[1] = 8;
        CHORD[5].data[1] = 6;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 2;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void sus2_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    {
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 3;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 6;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 4;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 5; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 7;
        CHORD[3].data[1] = 7;
        CHORD[4].data[1] = 5;
        CHORD[5].data[1] = 5;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 8;
        CHORD[3].data[1] = 8;
        CHORD[4].data[1] = 6;
        CHORD[5].data[1] = 6;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 7; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 9;
        CHORD[3].data[1] = 9;
        CHORD[4].data[1] = 7;
        CHORD[5].data[1] = 7;
        break;
    
    case 5: //Fa (F)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 8; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 10;
        CHORD[3].data[1] = 10;
        CHORD[4].data[1] = 8;
        CHORD[5].data[1] = 8;
        break;
    
    case 6: //Fa# (F#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 9; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 11;
        CHORD[3].data[1] = 11;
        CHORD[4].data[1] = 9;
        CHORD[5].data[1] = 9;
        break;
    
    case 7: //Sol (G)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 10; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 12;
        CHORD[3].data[1] = 12;
        CHORD[4].data[1] = 10;
        CHORD[5].data[1] = 10;
        break;

    case 8: //Sol# (G#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 11; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 13;
        CHORD[3].data[1] = 13;
        CHORD[4].data[1] = 11;
        CHORD[5].data[1] = 11;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 7;
        CHORD[3].data[1] = 9;
        CHORD[4].data[1] = 10;
        CHORD[5].data[1] = 7;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 8;
        CHORD[3].data[1] = 10;
        CHORD[4].data[1] = 11;
        CHORD[5].data[1] = 8;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 9;
        CHORD[3].data[1] = 11;
        CHORD[4].data[1] = 12;
        CHORD[5].data[1] = 9;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void sus4_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    {
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 6;
        CHORD[5].data[1] = 3;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 6;
        CHORD[4].data[1] = 7;
        CHORD[5].data[1] = 4;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 5; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 7;
        CHORD[3].data[1] = 7;
        CHORD[4].data[1] = 8;
        CHORD[5].data[1] = 5;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 8;
        CHORD[3].data[1] = 8;
        CHORD[4].data[1] = 9;
        CHORD[5].data[1] = 6;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 7; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 9;
        CHORD[3].data[1] = 9;
        CHORD[4].data[1] = 10;
        CHORD[5].data[1] = 7;
        break;
    
    case 5: //Fa (F)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 8; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 10;
        CHORD[3].data[1] = 10;
        CHORD[4].data[1] = 11;
        CHORD[5].data[1] = 8;
        break;
    
    case 6: //Fa# (F#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 9; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 11;
        CHORD[3].data[1] = 11;
        CHORD[4].data[1] = 12;
        CHORD[5].data[1] = 9;
        break;
    
    case 7: //Sol (G)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 10; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 12;
        CHORD[3].data[1] = 12;
        CHORD[4].data[1] = 13;
        CHORD[5].data[1] = 10;
        break;

    case 8: //Sol# (G#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 11; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 13;
        CHORD[3].data[1] = 13;
        CHORD[4].data[1] = 14;
        CHORD[5].data[1] = 11;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 7;
        CHORD[3].data[1] = 9;
        CHORD[4].data[1] = 10;
        CHORD[5].data[1] = 10;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 8;
        CHORD[3].data[1] = 10;
        CHORD[4].data[1] = 11;
        CHORD[5].data[1] = 11;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 9;
        CHORD[3].data[1] = 11;
        CHORD[4].data[1] = 12;
        CHORD[5].data[1] = 12;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void min9_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    {
    case 0: //Do (C)
        CHORD[0].data[1] = 3; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 3;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 127;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 127;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 6;
        CHORD[4].data[1] = 6;
        CHORD[5].data[1] = 127;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 2;
        break;
    
    case 5: //Fa (F)
        CHORD[0].data[1] = 1; 
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 3;
        break;
    
    case 6: //Fa# (F#)
        CHORD[0].data[1] = 2; 
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 4;
        break;
    
    case 7: //Sol (G)
        CHORD[0].data[1] = 3; 
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 127;
        CHORD[5].data[1] = 127;
        break;

    case 8: //Sol# (G#)
        CHORD[0].data[1] = 4; //"do not play this string"
        CHORD[1].data[1] = 6; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 6;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 3;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 6; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 6;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 127;
        CHORD[5].data[1] = 127;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 2; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 2;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}

void maj9_1(){
    switch (ROOTnOTE.data[1]-(12*OCT))
    {
    case 0: //Do (C)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 4;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 127;
        break;

    case 1: //Do# (C#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 4; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 5;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 127;
        break;
    
    
    case 2: //Re (D)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 0;
        break;
    
    case 3: //Re# (D#)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 1;
        break;
    
    case 4: //Mi (E)
        CHORD[0].data[1] = 0; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 2;
        break;
    
    case 5: //Fa (F)
        CHORD[0].data[1] = 1; 
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 3;
        CHORD[3].data[1] = 0;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 0;
        break;
    
    case 6: //Fa# (F#)
        CHORD[0].data[1] = 127; 
        CHORD[1].data[1] = 127; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 1;
        break;
    
    case 7: //Sol (G)
        CHORD[0].data[1] = 3; 
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 4;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 3;
        CHORD[5].data[1] = 127;
        break;

    case 8: //Sol# (G#)
        CHORD[0].data[1] = 4; //"do not play this string"
        CHORD[1].data[1] = 3; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 5;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 4;
        CHORD[5].data[1] = 127;
        break;

    case 9: //La (A)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 0; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 2;
        CHORD[3].data[1] = 1;
        CHORD[4].data[1] = 0;
        CHORD[5].data[1] = 0;
        break;
    
    case 10: //La# (A#)
        CHORD[0].data[1] = 1; //"do not play this string"
        CHORD[1].data[1] = 1; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 0;
        CHORD[3].data[1] = 2;
        CHORD[4].data[1] = 1;
        CHORD[5].data[1] = 1;
        break;

    case 11: //si (B)
        CHORD[0].data[1] = 127; //"do not play this string"
        CHORD[1].data[1] = 2; //here I'm just putting the tab number later on the proper note will be calculated
        CHORD[2].data[1] = 1;
        CHORD[3].data[1] = 3;
        CHORD[4].data[1] = 2;
        CHORD[5].data[1] = 127;
        break;

    default:
        //if this happens we got an error
        printf("\n Octave: %d --- Note: %d",OCT,ROOTnOTE.data[1]);
        break;
    }
}


