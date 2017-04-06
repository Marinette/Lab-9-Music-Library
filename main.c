//
// APS105-F15 Lab 8 Lab8.c
//
// This is a program written to maintain a personal music library,
// using a linked list to hold the songs in the library.
//
// Author: Meggie Chen
// Student Number: <Your Student Number Goes Here>
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// A node in the linked list

// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.
#define MAX_LENGTH 1024
#define MAX_LIBRARY_SIZE 100

// Declarations of support functions
// See below the main function for descriptions of what these functions do

void getStringFromUserInput(char s[], int arraySize);
void songNameDuplicate(char songName[]);
void songNameFound(char songName[]);
void songNameNotFound(char songName[]);
void songNameDeleted(char songName[]);
void artistFound(char artist[]);
void artistNotFound(char artist[]);
void printMusicLibraryEmpty(void);
void printMusicLibraryTitle(void);

typedef struct song
{
    char songName[MAX_LENGTH];
    char artist[MAX_LENGTH];
} Song;

typedef Song song;

// Declarations of linked list functions
//
// Declare your own linked list functions here.
//

void printLibrary(int numSongs, song musicLibrary[]) {
    
    if (numSongs == 0) {
        printMusicLibraryEmpty();
    }

    else {
        printMusicLibraryTitle();
        for (int position = 0; position < numSongs; position++) {
            printf("\n%s\n", musicLibrary[position].songName);
            printf("%s\n", musicLibrary[position].artist);
        }
    }
return;

}

void cocktailSort (song songLibrary[], int size) {
    char temp[MAX_LENGTH];
    bool swaps = true;
    
    //outer loop
    for (int top = size -1; top > 0 && swaps ; top--) {
        int bottom = size - top - 1;
        //exit outer loop if no swap
        swaps = false; 
        
        //loop for each pass from bot to top
        for (int i = 0; i < top; i++) {
            if (strcmp(songLibrary[i].artist,songLibrary[i+1].artist)>0) {
                
                strcpy(temp, songLibrary[i+1].artist);
                strcpy(songLibrary[i+1].artist, songLibrary[i].artist);
                strcpy(songLibrary[i].artist,temp);
                
                strcpy(temp, songLibrary[i].songName);
                strcpy(songLibrary[i].songName, songLibrary[i+1].songName);
                strcpy(songLibrary[i+1].songName, temp);
                swaps = true;
            }            
        }//end of check for each pair from bottom to top   
        
        //check from top to bottom
        for (int j = top-1; j > 0; j--) { //you already know that top is the largest
            
            if (strcmp(songLibrary[j].artist,songLibrary[j-1].artist) < 0) {
                strcpy(temp,songLibrary[j].artist);
                strcpy(songLibrary[j].artist,songLibrary[j-1].artist);
                strcpy(songLibrary[j-1].artist, temp);
                
                strcpy(temp,songLibrary[j].songName);
                strcpy(songLibrary[j].songName,songLibrary[j-1].songName);
                strcpy(songLibrary[j-1].songName, temp);
                swaps = true;
                
            }
            //end of checking each pair
            
        }
        //end of check from top to bottom
    }
    //end of outer loop
    
return;
}
//end of cocktailSort



int main(void) {
    
    song musicLibrary[MAX_LIBRARY_SIZE];
    char input[MAX_LENGTH];
    int numSongs = 0;
    
    // Announce the start of the program
    printf("%s", "Personal Music Library.\n\n");
    printf("%s", "Commands are I (insert), D (delete), S (search by song name),\n"
           "P (print), Q (quit).\n");
    
    char response;
    
    do {
        printf("\nCommand?: ");
        getStringFromUserInput(input, MAX_LENGTH);
        
        // Response is the first character entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);
        
        if (response == 'I') {
            // Insert a song into the linked list.
            // Maintain the list in alphabetical order by song name.
            numSongs++;
            printf("Song name: ");
            getStringFromUserInput(input, MAX_LENGTH);
            strcpy(musicLibrary[numSongs-1].songName, input);
            
            printf("Artist: ");
            getStringFromUserInput(input, MAX_LENGTH);
            strcpy(musicLibrary[numSongs-1].artist, input);
                      
        }
        
            
        else if (response == 'S') {
            //cocktail sort the songs
            cocktailSort(musicLibrary, numSongs);
            printLibrary(numSongs, musicLibrary);
            
        }
        else if (response == 'P') {
            // Print the music library.
            
         printLibrary(numSongs, musicLibrary);   
            
        }
        else if (response == 'Q') {
            ; // do nothing, we'll catch this below
        }
        else {
            // do this if no command matched ...
            printf("\nInvalid command.\n");
        }
    } while (response != 'Q');
    
    // Delete the entire linked list.
   
    //STATEMENT
    
    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE
    
    return 0;
}

// Support Function Definitions

// Prompt the user for a string safely, without buffer overflow
void getStringFromUserInput(char s[], int maxStrLength) {
    int i = 0;
    char c;
    
    while (i < maxStrLength && (c = getchar()) != '\n')
        s[i++] = c;
    
    s[i] = '\0';
}

// Function to call when the user is trying to insert a song name
// that is already in the personal music library.
void songNameDuplicate(char songName[])
{
    printf("\nA song with the name '%s' is already in the music library.\n"
           "No new song entered.\n", songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound(char songName[])
{
    printf("\nThe song name '%s' was found in the music library.\n",
           songName);
}

// Function to call when a song name was not found in the personal music library.
void songNameNotFound(char songName[])
{
    printf("\nThe song name '%s' was not found in the music library.\n",
           songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted(char songName[])
{
    printf("\nDeleting a song with name '%s' from the music library.\n",
           songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void)
{
    printf("\nThe music library is empty.\n");
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void)
{
    printf("\nMy Personal Music Library: \n");
}

// Add your functions below this line.

//   ADD STATEMENT(S) HERE