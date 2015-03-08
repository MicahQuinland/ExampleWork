//============================================================================
// Name        : Personal Phonebook app.c
// Author      : Juan Micah Quinland
// Version     :
// Description : Contact storage Phone Book database			 			
//============================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
       char FName[40];
       char LName[50];
       char PNum[20];
       }Friend;

char store(Friend *phonebook,int size);
Friend* retrieve(Friend *phonebook,int *size);

int main()
{   srand(time(NULL));
    int Selection, size=0, x=0, temp2=0; //Contains temporary variables
    int end, y=0, z=0, l=0, m=0;
    int No = 0;
    char CheckFName[40];
    char CheckLName[50];
    char temp[40] = "";
    char temp3[50] = "";
    char temp4[20] = "";
    char location[200] = "";
    Friend *phonebook= NULL; // Pointer to friend structure
    int Random = 0;
    FILE *pRead;
    FILE *pWrite;
    
    
           do {
    
    printf("Phone Book Application\n\n");
    printf("  1) Add friend\n");
    printf("  2) Delete friend\n");
    printf("  3) Show phone book\n");
    printf("  4) Alphabhetly sort phone book\n");
    printf("  5) Find phone munber\n");
    printf("  6) Select random friend\n");
    printf("  7) Store contacts to a file\n");
    printf("  8) Retrieve contacts from file\n");
    printf("  9) Delete all contacts\n");
    printf("  0) Exit\n\n");
    
    printf("What do you want to do: ");
    scanf("%d", &Selection);
    
    switch (Selection) {
           
           case 1: //Add friend

                phonebook = (Friend*) realloc(phonebook, sizeof(Friend) * (size+1)); //Checks if there is space for structure and sets the location back to phonebook
                if(phonebook==NULL)
                { printf("\nError in Memory allocation");
} //End If   
                else {    
                printf("\nFirst name: ");
                scanf("%s", phonebook[size].FName); // reads entry directly into the current structure array
                printf("\nLast name: ");
                scanf("%s", phonebook[size].LName);
                printf("\nPhone number: ");
                scanf("%s", phonebook[size].PNum);
                
                printf("\nRecord added to the phone book");
                size++; // Moves to the next array of phonebook
                              
} // End Else
                break;  
                
           case 2: //Delete friend by decreasing (variable size)
               printf("\nFirst name: ");
               scanf("%s", CheckFName);
               printf("\nLast name: ");
               scanf("%s", CheckLName);
               
               temp2 = -1;
               for ( y = 0; y < size; y++){
               if( strcmp(phonebook[y].FName,CheckFName) == 0 && strcmp(phonebook[y].LName,CheckLName) == 0 ){
                     temp2 = y;
                    
                     printf("\nContact has been deleted");
} // End If               
} //End For                  
             if ( temp2 == -1){
              printf("\nThe contact was not found"); 
              break;   
} // End If        
             
             for( z = temp2; z < size; z++){
              strcpy(phonebook[z].FName,phonebook[z+1].FName);  //copies data after delete, one space lower    
} // End For     
            for( l = temp2; l < size; l++){
              strcpy(phonebook[l].LName,phonebook[l+1].LName);      
} // End For
            for( m = temp2; m < size; m++){
              strcpy(phonebook[m].PNum,phonebook[m+1].PNum);      
} // End For   
               phonebook = (Friend*) realloc(phonebook, sizeof(Friend) * (size-1));
               size--;
               break;

           case 3: //Print phone book entries
                printf("\nPhone Book Entries: \n");
                for ( x = 0; x < size; x++){
                    printf("\n%s %s %s\n",phonebook[x].FName,phonebook[x].LName,phonebook[x].PNum);                     
} // End For               
               break;
               
           case 4: // Alphabetically sort
                for(x = 0; x < size; x++){
                      for (y = 0; y < size-1; y++){
                          if( strcmp(phonebook[y].FName,phonebook[y+1].FName) > 0){
                            strcpy(temp,phonebook[y].FName);
                            strcpy(temp3,phonebook[y].LName);
                            strcpy(temp4,phonebook[y].PNum);
                            strcpy(phonebook[y].FName,phonebook[y+1].FName);
                            strcpy(phonebook[y].LName,phonebook[y+1].LName);
                            strcpy(phonebook[y].PNum,phonebook[y+1].PNum);
                            strcpy(phonebook[y+1].FName,temp);
                            strcpy(phonebook[y+1].LName,temp3);
                            strcpy(phonebook[y+1].PNum,temp4);
                            } // End If
                } // Enf For
} // End For                     
                 printf("\nPhone Book Entries: \n");
                for ( x = 0; x < size; x++){
                    printf("\n%s %s %s\n",phonebook[x].FName,phonebook[x].LName,phonebook[x].PNum);                     
} // End For              
                break;
           
           case 5: //Find Phone Number
                printf("\nFirst name: ");
               scanf("%s", CheckFName);
               printf("\nLast name: ");
               scanf("%s", CheckLName);
               
               temp2 = -1;
               for ( y = 0; y < size; y++){
               if( strcmp(phonebook[y].FName,CheckFName) == 0 && strcmp(phonebook[y].LName,CheckLName) == 0 ){
                     temp2 = y;
                    
                     printf("\n%s %s, phone # is %s", CheckFName, CheckLName, phonebook[temp2].PNum);
} // End If               
} //End For                  
             if ( temp2 == -1){
              printf("\nThe contact was not found"); 
              break;   
} // End If        
                
                break;
                
           case 6: // Random entrie
                
               if(size > 0){
                Random = (rand() % size);
                printf("\n%s %s %s",phonebook[Random].FName,phonebook[Random].LName,phonebook[Random].PNum) ;
                break;} 
				else {
				printf("\nThe are no entries, try another option\n");
				break;}
                
           case 7:  // Save contacts to file
           
                store(phonebook, size); 
                break;
           
           case 8:  //Retrieve contacts from file
                
              phonebook=retrieve(phonebook, &size); 
              size--;
              break;                
                
           case 9: // Delete all contacts
                printf("\nAre you sure you want to delete all contacts? \n 1) Yes\n 2) No\n");
                scanf("%d", &No);
                switch (No){
                case 1:
                   printf("\nAll contacts are deleted");
                   free(phonebook);
                   size = 0;
                   break;                
                
                case 2: 
                   printf("\nContacts saved");                 
                   break;
} // End Switch
                break;
                
           case 0: //Exit
               printf("\nGood Bye!");
               free(phonebook);
               break; 
               
            default: //Wrong number entered
               printf("You did not enter a number between 0 and 9");   
    
} // End Switch   
    getch();
    system("cls"); //clears screen for new operation
} // End Do while
    while (Selection != 0); //Infintie loop ends
    return 0;
} // End Main program

char store(Friend *phonebook,int size){  
     int x=0;
    FILE *pRead;
    FILE *pWrite;
    char location[200] = "";
     
     printf("Enter the file name and locatin you want to save to, add .txt to the end\n");
        scanf("%s",location);
     if(location != NULL){
                pWrite = fopen(location,"w");
                if (pRead==NULL){
                   printf("\nFile Can't be Opened");
} // End If
                else {
                  for ( x = 0; x < size; x++){
                    fprintf(pWrite,"%s %s %s\n",phonebook[x].FName,phonebook[x].LName,phonebook[x].PNum);                     
} // End For 
}// End Else     
                fclose(pWrite);
} // End If
                else{
                  pWrite = fopen("Phonebook.txt","w");
                if (pRead==NULL){
                   printf("\nFile Can't be Opened");
} // End If
                else {
                  for ( x = 0; x < size; x++){
                    fprintf(pWrite,"%s %s %s\n",phonebook[x].FName,phonebook[x].LName,phonebook[x].PNum);                     
} // End For 
}// End Else     
                fclose(pWrite); 
} // End Else            
} // End Store Function

Friend* retrieve(Friend *phonebook,int *size){
    
     int x=0;
    FILE *pRead;
    FILE *pWrite;
    char location[200] = "";
    
     printf("Enter the file locatin you want to retrieve from, add .txt to the end\n");
                scanf("%s", location);
                if(location != NULL){
                   pRead = fopen(location,"r");
                     if(pRead!=NULL){
                  while(!feof(pRead)){
                              phonebook = (Friend*) realloc(phonebook, sizeof(Friend) * (x+1)); //Checks if there is space for structure and sets the location back to phonebook
                                if(phonebook==NULL)
                                  { printf("\nError in Memory allocation");
} //End If   
                      else {
                               fscanf(pRead,"%s %s %s",phonebook[x].FName,phonebook[x].LName,phonebook[x].PNum);
                                printf("\n%s %s %s\n",phonebook[x].FName,phonebook[x].LName,phonebook[x].PNum);
                               
                                x++;
} // End Else                                
} // End While
                            fclose(pRead);
                          
               
} // End If
                  else{
                         printf("File Can't be Opened");
} // End Else 
} // End If
                  else{
                       pRead = fopen("Phonebook.txt","r");
                if(pRead!=NULL){
                  while(!feof(pRead)){
                              phonebook = (Friend*) realloc(phonebook, sizeof(Friend) * (x+1)); //Checks if there is space for structure and sets the location back to phonebook
                                if(phonebook==NULL)
                                  { printf("\nError in Memory allocation");
} //End If   
                      else {
                               fscanf(pRead,"%s %s %s",phonebook[x].FName,phonebook[x].LName,phonebook[x].PNum);
                                printf("\n%s %s %s\n",phonebook[x].FName,phonebook[x].LName,phonebook[x].PNum);
                                
                                x++;
} // End Else                                
} // End While
                            fclose(pRead);
                          
               
} // End If
                  else{
                         printf("File Can't be Opened");
} // End Else  
} // End Else    
*size=x;     
return phonebook;
} // End Retrieve Function
