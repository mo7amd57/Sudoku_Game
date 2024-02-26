#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <conio.h>



void Play_Sound_WAIT(void)
{
     PlaySound(TEXT("Sound/wait.wav"),NULL,SND_ASYNC);
}

void Stop_Sound(void)
{
    PlaySound(NULL, NULL, SND_PURGE);
}

void Play_Sound_WRONG(void)
{
     PlaySound(TEXT("Sound/wrong.wav"),NULL,SND_ASYNC);
}

void Play_Sound_longWRONG(void)
{
     PlaySound(TEXT("Sound/Long_wrong.wav"),NULL,SND_ASYNC);
}

void Play_Sound_SUCCESS(void)
{
     PlaySound(TEXT("Sound/success.wav"),NULL,SND_ASYNC);
}


void Play_Sound_WOW(void)
{
     PlaySound(TEXT("Sound/wow.wav"),NULL,SND_ASYNC);
}





