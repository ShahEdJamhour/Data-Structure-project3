#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include <strings.h>
#include<string.h>
#include<math.h>


/*
Shahed Jamhour
1180654

*/



/*
In this project you can insert, delete, search, In the two data structures
                         The AVL Tree & Hash Table.
*/



char tempdict[250];



typedef struct node *AVL;

  struct node
 {

   char Data[250];
   char Meanings[20][250];
   char Synonym[250];
   char Antonym[250];
   int CountMeanings;
    int height;
   AVL left;
   AVL right;
 };

struct HashTable
{
    char Data[250];
    int Tag;
   // boolean del ; // remark the cell deleted
};

struct HashTable ttable ;

 ///_________________________________________Functions ___________________________________________________
void DisplayMainMenu();
void HashMenu();
void TreeMenu();
AVL InorderSuccessorRightTree(AVL );
AVL Insertion(AVL , char [],char [],char [], char []);
AVL deletion(AVL , char []);
void FileReader(int *);
const char * GetData();
AVL Search(AVL ,char *);
void InOrderHashing(AVL);
void HashDelete(int);
int SearchInHashed(char* );
void Rehash(int );
void ReadTreeInfo(AVL );
void InsertHash(char *);
void HashFunction();
void InorderFirstCharachter(AVL  ,char );
int GetPrime(int );
int StringHash(char *);
void Hash2Function(char * ,int );

///////////////////////////////////////////////////////////////////////////


struct HashTable *Array,*TempArray;;//Array represent the hash table and the other  represents  temp hash table;
int count;//This variable represent the number of filled cells in the hash table
char HashARR[100][50]; // to save the words in the tree


/// Menues

///////////////////////////////////////////////////////////////////////////
///                          Main Menu                                    //
//////////////////////////////////////////////////////////////////////////


void DisplayMainMenu()
{

    printf(" \n");
    printf(" \t\t\t ______________________Main Menu________________________ \n");
    printf("\t\t\t|                                                       | \n");
    printf("\t\t\t| Please choose one of the following:                   |\n");
    printf("\t\t\t|     1.Display AVL Tree Menu.                          |\n");
    printf("\t\t\t|     2.Display Table Menu.                             |\n");
    printf("\t\t\t|     3.Exit.                                           |\n");
    printf("\t\t\t|_______________________________________________________|\n");



}

///////////////////////////////////////////
///          Tree Menu
///////////////////////////////////////////

void TreeMenu()
{

    printf(" ____________________________________________________________________________________ \n");
    printf("| Enter The Number Of Operation You Want To Do Please :                              |\n");
    printf("|     1.Read From File.                                                              |\n");
    printf("|     2.Insertion A new word to the dictionary with its associated data.             |\n");
    printf("|     3.Find a word and update it.                                                   |\n");
    printf("|     4.List words in the dictionary in lexicographic order.                         |\n");
    printf("|     5.List all synonym and antonyms of a given word.                               |\n");
    printf("|     6.List all words that start with the same first letter in lexicographic order. |\n");
    printf("|     7.Delete a word from the dictionary.                                           |\n");
    printf("|     8.Delete all words that start with a specific letter.                          |\n");
    printf("|     9.Save all words in file Dictionary.data.                                      |\n");
    printf("|     10.Exit and go back to main menu.                                              |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("# Of Operation :  ");



}

int f= 0;
/////////////////////////////////////////////////////////////////
///                   Hash Menu                                 /
////////////////////////////////////////////////////////////////

void HashMenu()
{


    printf(" ___________________________________________________________________________________ \n");
    printf("| Enter The Number Of Operation You Want To Do Please :                              |\n");
    printf("|     1.Print hashed table                                                           |\n");
    printf("|     2.Print out table size.                                                        |\n");
    printf("|     3.Print out the used hash function.                                            |\n");
    printf("|     4.Insertion a new record into the hash table                                   |\n");
    printf("|     5.Search for a specific word.                                                  |\n");
    printf("|     6.Delete a specific record.                                                    |\n");
    printf("|     7.Save hash table back to file.                                                |\n");
    printf("|     8.Exit and go to main menu                                                     |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("# Of Operation : ");





}

 // tree inorder
 void InOrder(AVL root){
   if(!root)
     return;
   InOrder(root->left);
   printf("The Word:  %s :\n",root->Data);
   int i;
   printf(" It's Meaning(s): ");
   for (i = 0 ; i < root->CountMeanings ; i++)
   printf("  Meaning (%d):%s ",i+1,root->Meanings[i]);
   printf("/ It's Synonym  : %s  / ",root->Synonym);
   printf("It's antonym : %s  \n ",root->Antonym);

   printf("\n");
   InOrder(root->right);
 }



 /////////////////////////////////////////////////////////////////
//function to print in order to a file
////////////////////////////////////////////////////////////////
void PrintTreeToFile(AVL Tr,FILE * file)
{
  if(Tr!=NULL)
  {
      PrintTreeToFile(Tr->left,file);//recursive call
      fprintf(file,"%s\n",Tr->Data);
      PrintTreeToFile(Tr->right,file);
  }
}


int SizeOfTable = 0;//The size of the hash table

int main()
{

     printf("\n\n\t\t\t In This Project, You can read ,insert,Search, delete,In the two data structure:\n") ;
    printf("\t\t\t The AVL Tree & Hash Table.\n\n") ;
     int i;
     int u;
     int y;
     int x;
     int m;

     AVL tree = NULL;
     int InputDataCount; // Count the data
     FileReader(&InputDataCount);
     char Data[InputDataCount][250];

     int Choice;//choice from menu
     int Choice2; //This represent the selection from a minor menu
     count=0;//initialize the count variable
     int Flag=0;//Flag variable
     int flag2=0;
     int CheckTree =0;
       FILE * file;
    char StoreData[100][50]; // for deletion with specific char
    while(1){
     DisplayMainMenu();//print main menu on screen


     scanf("%d",&Choice);//read the selected number
     system("cls");



    if(Choice==1){
    TreeMenu();//print the menu in the screen
     printf("\n  ");
     scanf("%d",&x);//read choice
     system("cls");//clear screen

    while(x !=10)
    {


        if(x==1) //Read file
        {

              for (i = 0 ; i < InputDataCount ; i++)
            {
                 strcpy(Data[i],GetData());
            }
            char word[100];
            char meaning[100],Synonym[100],antonym[100];
            for (i = 0 ; i < InputDataCount ; i++)
            {
                char *p;
                int c5;
                char *yy;
                char x0[strlen(Data[i])]; // store the date in order to token it
                strcpy(x0,Data[i]);
                yy = strtok(x0,":");
                strcpy(word,yy);
                strcpy(StoreData[i],word);
                yy = strtok(NULL,"/");
                strcpy(meaning,yy);
                yy = strtok(NULL,"*");
                strcpy(Synonym,yy);
                yy = strtok(NULL,"*");
                strcpy(antonym,yy);
                tree = Insertion(tree,word,meaning,Synonym,antonym);
            }
            printf("\n");
            printf(" ");
            printf("  \n     File has been Read Successfully :) \n\n ");
            CheckTree = 1 ;
        }
        else if(x==2) // Insertion a new word
            {
                if(CheckTree ==0)
                    printf("Make sure you have read the file first \n");

                else{

                printf(" Please enter data as follows \n");
                printf(" Word: meaning1, meaning2, ... , meaningN / a Synonym * an antonym \n");
 char NewWords[100];
                scanf("%s",NewWords);//Scan the word to Insertion

                char InsWord[100];
                char InsMean[100];
                char InsAntonym[100];
                char InsSynonym[100];

                 char x[strlen(NewWords)]; // store the date to token it
                char *p;

                strcpy(x,NewWords);
                 p = strtok(x,":"); strcpy(InsWord,p);
                 strcpy(StoreData[InputDataCount],InsWord);
                 ++InputDataCount;
                 p = strtok(NULL,"/");
                 strcpy(InsMean,p);
                 p = strtok(NULL,"*");
                 strcpy(InsSynonym,p);
                 p = strtok(NULL,"*");
                 strcpy(InsAntonym,p);

                 tree = Insertion(tree,InsWord,InsMean,InsSynonym,InsAntonym);


            }
            }
        else if(x==3)//Search for a given word
            {
                    if(CheckTree ==0)
                    printf(" PLS Make sure you have read the tree from file first \n");

                else{
                         printf("  ");
                    char s_word[100];

                    printf("  Enter word you wish to find \n");

                    scanf("%s",s_word);//Store the  entered word
                    // if the words is in the tree
                    if(Search(tree,s_word) != NULL){
                        printf("  Word Found :))  \n  \n");
                        AVL S = Search(tree,s_word);
                        printf("%s :\n",S->Data);
                        int q ;
                        printf("Meanings : ");
                        for(q=0;q<S->CountMeanings ;++q)
                            printf("%s,",S->Meanings[q]);
                        printf("  Synonym : %s, Antonym : %s \n",S->Synonym,S->Antonym);


                    }
                    else
                    {
                        printf(" WORD NOT FOUND    ://   \n");

                    }

            }
            }
        else if(x==4)// List words in the dictionary in lexicographic order
            {
                if(CheckTree ==0)
                    printf("PLS Make sure you have read the tree from file first \n");

                else{
                InOrder(tree);
            }
            }
        else
            if(x==5)//List all Synonym and antonyms of a given word
            {
                if(CheckTree ==0)
                    printf("PLS Make sure you have read the tree from file first  \n");

                else{
                char GW[100];
                printf("Enter the word that you wish to print Synonym and antonyms of\n\n");

                scanf("%s",GW);//Store the word entered by the user
                  AVL S= Search(tree,GW);
                  if(S!=NULL){
                      printf("\n");
                        printf(" Entered word: %s \n", GW);
                        printf(" \n");

                       printf(" It's Synonym(s):  %s  \n",S->Synonym);
                       printf(" It's Antonym(s): %s \n",S->Antonym);

                       printf("\n\n");




                  }
                  else{
                        printf("\n");

                       printf("Word Not Found  \n");

                       printf("\n");
                  }
           }
            }
        else
           if(x==6)//List all words in lexicographic order that belong to the same first character
           {
               if(CheckTree ==0)
                    printf("PLS Make sure you have read the tree from file first  \n");

                else{
               char Character[10] ;
               printf("Enter the character \n");
               scanf("%s",Character);
               InorderFirstCharachter(tree,Character[0]);
            }
           }
        else if(x==7)// Delete a word
            {
                if(CheckTree ==0)
                {


                    printf("PLS Make sure you have read the tree from file first \n");
                    printf("");
                     printf("\n");
                }

                else{
                char DeletedWord[100];
                char Tmp[50];
                printf("  Enter the word that you want to delete \n");
                    printf(" \n ");
                    scanf("%s",DeletedWord);
                    tree = deletion(tree,DeletedWord);//Delete the entered word
                    printf ("\n");
                    printf (" ");
                    printf(" Word Deleted Successfully :))  ");
            }
            }
        else if(x==8)//Delete all words that start with a specific letter
            {
                if(CheckTree ==0)
                    printf("PLS Make sure you have read the tree from file first  \n");

                else{
                    char xi[10];
               char letter[10] ;
               int i ;

               printf("Enter Character \n");
               scanf("%s",letter);
               for(i=0;i<InputDataCount;++i){
                if(StoreData[i][0]==letter[0])
                {


                    tree = deletion(tree,StoreData[i]);
                }
               }



            }
            }
        else if(x==9)//Save all words in file dictionary Data
            {
                if(CheckTree ==0)
                    printf("PLS Make sure you have read the tree from file first  \n");

                else{


                FILE *output;
                output = fopen("Dictionary.txt","w");//open file
                if (output==NULL)

                    {
                        {


                        printf("\n");                        printf(" oops");

                           printf("  Can't open file\n");
                           printf("");
                        }

                    }
                    else
                    {
                        PrintTreeToFile(tree,output);// call the function which  prints the tree to the file
                        printf("\n\n");
                        printf("\t Your Dictionary is ready  ");
                        printf(" ^-^ ");
                        printf("\n");
                    }
                fclose(output);

             }
            }
        else if(x==10) // exit
             {

                 break ;
             }

        else if (x > 10)// invalid input
                {
printf(" Choose again ?");
            }
        printf("\n       ** Press Any Key Then Enter");
        printf(" To go back to the menu >");

        char ch=getchar();
        while (ch=='\n')
        ch=getchar();
        system("cls");//clear screen
        TreeMenu();//print tree menu in the screen
        printf("  ");
        scanf("%d",&x);
        system("cls");//clean screen
    }
}

    if(Choice==2){
            if(CheckTree ==1 ){
    HashMenu();//print hash menu in the screen
     printf("\n  ");
     scanf("%d",&x);//read the selected number
     system("cls");//clean screen

    while(x !=9)
    {
        if(x==1)
        {
            ReadTreeInfo(tree);
            Flag = 1 ;
            int i;//loop variable
            char *Hm=" ";
                char *c=" ";
                if(Flag==1)
                {
                    printf("Words :%-15s \n",c);
                    for(i=0;i<SizeOfTable;i++)
                    {
                        if(Array[i].Tag == 1)
                            printf("%d   %s \n",i,Array[i].Data);
                        else
                            printf("%d.    %-15s \n",i,c);
                    }
                }
        }
        else

            if(x==2)// Print table size
            {
                {



                 if(Flag==1)
                 {

                     printf(" Size Of Table %d \n",SizeOfTable);
                 }
                 else
                 {

                     printf("  Make sure you have read the file first\n");
                 }
                }

            }
        else
            if(x==3)// Print out used hash function
            {
               if(Flag==1)
                     HashFunction();
                 else
                     printf("  You should first read the file that contains the words.\n");;
            }
        else
            if(x==4)//Insertion a new record to hash table
            {
                char m;
                 int k=0;
                 if(Flag==1)
                 {
                     char word[60];//New word
                     printf("  Enter the word :- \n");
                     printf("  ");
                     //Scan the word
                     scanf("%s",word);
                     printf("\n");
                     InsertHash(word);//Insertion the new record
                     printf("  Insertion is done\n");
                 }
                 else
                 {

                 printf(" Opps");
                     printf(" Read file first \n");
                     printf(" (Number 1 from the previous menu)  ");
                 }
           }
        else if(x==5)//Search for a specific word
           {
              int index;
                 char word[60];
                 char m1;
                 int k2=0;
                 if(Flag==1)
                 {
                     printf("  Enter the word :   \n");
                     printf("  ");
                     scanf("%s",word);//Scan the ID to Search for
                     index=SearchInHashed(word);//Search for the record
                     if(Array[index].Tag==1)//the record is exist
                     {
                         printf(" Word found :)) \n");
                         printf("Index of entered word");
                         printf("  %d \n",index);
                     }
                     else
                     {
                         printf("  This word is not exist\n");//The record is not exist

                     }
                 }
                 else
                    printf("  You should first read the file that contains the words.\n");
            }
        else if(x==6)// Delete a specific record.
            {

                 int index;//The index of the record in the hash table
                 char word[100];
                 printf("  Enter the word that you want to delete:-\n");
                 printf("  ");
                 scanf("%s",word);//scan the word
                 index=SearchInHashed(word);//Search for the record
                 if(Array[index].Tag==1)//the record is exist in the hash table
                 {
                     HashDelete(index);//delete the record
                     printf("  Done deleting \n");
                 }
                 else
                     printf(" Word not found \n");
            }
        else
            if(x==7)//Save hash table back to file
            {
               if(Flag==1)
                {
                    int i;
                    file=fopen("HashTableFile.txt","w");//open the output file
                    fprintf(file,"     Words : \n");
                    for(i=0;i<SizeOfTable;i++)
                        if(Array[i].Tag==1)
                        {
                            fprintf(file,"  %d  %-15s  ",i,Array[i].Data);
                            fputs("\n",file);
                        }
                        else{
                            fprintf(file,"  %d  ",i );
                             fprintf(file,"\n");
                        }
                         printf(" \n\n");
                        printf(" Done printing on file\n");
                    fclose(file);//close the file
                }
                else
                {
                    printf("oops! ");

                    printf("  Make sure you have read the file first.\n");

                }

            }
        else if(x==8) // exit
             {
                 printf("\n Exiting ...");

                 break ;
             }

        else if(x > 8)// invalid input
                {
                printf("\n  Choose Again\n");

            }

        printf("\n   Press any key to go back to the menu \n\n");
        printf("  ");
        char ch=getchar();
        while (ch=='\n')
        ch=getchar();
        system("cls");
        HashMenu();//print hash menu
        scanf("%d",&x);
        system("cls");
    }
    }
    else
    {
printf("\n\n");
    printf("\t OOPS  ");
        printf(" You have not created a tree first !\n");
    }

    }
   else if(Choice == 3){
            printf("\n Exiting.... \n");
             printf("\n Bye.... \n");

        exit(0);
    }
    else if(Choice!=1 || Choice!=2 || Choice!=3){
        printf("\n\n Choose again") ;

        printf(" Please  : \n\n");

    }
    }

    return 0;
}

//////////////////////////
 ///ReadFile
 //////////////////////////////////////////////////////////////////
void FileReader(int *counter)
{
    char x[250];
    int ii=0;
    *counter = 0;
    FILE *in;
    in = fopen("Words.txt","r");

    while (fgets(x,250,in)!= NULL)
    {
        (*counter)++;
    }
    fclose(in);
}



////////////////////////////////////////////////////////////////
//Function to Search for a word in the tree
///////////////////////////////////////////////////////////////

AVL Search(AVL Tr,char *word)
{
    if(Tr==NULL)
        return Tr;
    if(strcmp(word,Tr->Data)<0)//The node is less than T
        return Search(Tr->left,word);
    else
        if(strcmp(word,Tr->Data)>0)//The node is greater than T
            return Search(Tr->right,word);
    else
        return Tr;
}


////////////////////////////////////////////////////////////////////////////////////////////
 AVL get_node(char val[250],char meaning[250] , char Synonym[250] , char antonym[250]){
   AVL new_node = (AVL)malloc(sizeof(struct node));
   new_node->left = NULL;

   new_node->right = NULL;
   new_node->CountMeanings = 0;

   strcpy(new_node->Data, val);
   strcpy(new_node->Synonym,Synonym);

   strcpy(new_node->Antonym,antonym);
   char k[strlen(meaning)];
   strcpy(k,meaning);
   char *p;
   p = strtok(k,",");
    strcpy(new_node->Meanings[0],p);

   new_node->CountMeanings++;
   while (p!= NULL)
   {
       p = strtok(NULL,",");
       if(p!= NULL)
       {
        strcpy(new_node->Meanings[new_node->CountMeanings], p);
        new_node->CountMeanings++;
       }
   }
   new_node->height = 1;
   return new_node;
 }
 //////////////////////////////////////////////////////////////////////
 int GetHeight(AVL root){
   if(!root)
     return 0;
   else
     return root->height;
 }
 ////////////////////////////////////////////////////////////////////////
 int BalanceT(AVL root){
   if(!root)
     return 0;
   return (GetHeight(root->left) - GetHeight(root->right));
 }
 //////////////////////////////////////////////////////////////////////////
 int maximum(int a, int b){
  return (a > b) ? a : b;
 }
 ////////////////////////////////////

 AVL minValueNode(AVL root)
{
    AVL current = root;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}
///////////////////////////////////////////////

 /////////////////////////////////////////////////////////////////////
 AVL LeftRotation(AVL root){
   AVL right = root->right;
   AVL left = right->left;
   //perform rotation
   right->left = root;
   root->right = left;
   //update heights of the rotated nodes
   root->height = maximum(GetHeight(root->left), GetHeight(root->right)) + 1;
   right->height = maximum(GetHeight(right->left), GetHeight(right->right)) + 1;
   //return new root
   return right;
 }

///////////////////////////////////


 int Heightt( AVL P )
{
    if( P == NULL )
        return -1;
    else
        return P->height;
}
 ////////////////////////////////////////////////////////////////////////////
 AVL right_rotate(AVL root){
   AVL left = root->left;
   AVL right = left->right;
   //perform rotation
   left->right = root;
   root->left = right;
   //update heights of the rotated nodes
   root->height = maximum(GetHeight(root->left), GetHeight(root->right)) + 1;
   left->height = maximum(GetHeight(left->left), GetHeight(left->right)) + 1;
   //return new root
   return left;
 }
 /////////////////////////////////////////////////////////////////////////////////////////////////
 //This function to Insertion a node to the tree
 AVL Insertion(AVL root, char val[50],char meaning[200],char Synonym[200], char antonym[200]){
  /* 1.  Perform the normal BST insertion */
   if(!root){

     AVL new_node = get_node(val,meaning,Synonym,antonym);
     return new_node;
   }
   if(strcmp(root->Data,val) > 0)
   {
     root->left = Insertion(root->left, val,meaning,Synonym,antonym);
   }
   else
   {
     root->right = Insertion(root->right, val,meaning,Synonym,antonym);
   }
  /* 2. Update height of this ancestor node */
   root->height =1 + maximum(GetHeight(root->left), GetHeight(root->right)) ;
   //check for balancing
   /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
   int balance = BalanceT(root);
    // Left Right Case
   if(balance > 1 && strcmp(root->left->Data, val) > 0){
     root = right_rotate(root);
   }
       // Left Left Case
   else if(balance < -1 && strcmp(root->right->Data , val)< 0){
     root = LeftRotation(root);
   }

   //left-right case
   else if(balance > 1 && strcmp(root->left->Data, val)< 0){
     root->left = LeftRotation(root->left);
     root = right_rotate(root);
   }
   // Right Left Case
   else if(balance < -1 && strcmp(root->right->Data  ,val) > 0){
     root->right = right_rotate(root->right);
     root = LeftRotation(root);
   }
   return root;
 }

 ////////////////////////////////////////////////////////////
///balance the node when deleting
 /////////////////////////////////////////////////////
 AVL BalanceTree(AVL root){
   AVL x, *y;
   int LeftHeight,rheight;
   LeftHeight = GetHeight(root->left);
   rheight = GetHeight(root->right);
   if(LeftHeight >= rheight)
     x = root->left;
   else
     x = root->right;
   LeftHeight = GetHeight(x->left);
   rheight = GetHeight(x->right);
   if(x == root->left){
     if(LeftHeight >= rheight){
       y = x->left;
     }
     else
       y = x->right;
   }
   if(x == root->right){
     if(LeftHeight > rheight){
       y = x->left;
     }
     else
       y = x->right;
   }
   //left-left case
   if(root->left == x && x->left == y){
     root = right_rotate(root);
   }
   //right-right case
   else if(x == root->right && x->right == y){
     root = LeftRotation(root);
   }
   //left-right case
   else if(x == root->left && y == x->right){
     root->left = LeftRotation(root->left);
     root = right_rotate(root);
   }
   //right-left case
   else if(x == root->right && y == x->left){
     root->right = right_rotate(root->right);
     root = LeftRotation(root);
   }
   return root;
 }

 ////////////////////////////////////////////////////////////
 //utility function to find InOrder successor
 //////////////////////////////////////////////////////
 AVL InorderSuccessorRightTree(AVL root){
   AVL temp = root->right;
   while(temp->left){
     temp = temp->left;
   }
   return temp;
 }
 /////////////////////////////////////////////////////////////
 // //This function to delete a node from the tree
 AVL deletion(AVL root, char val[200]){
   //normal deletion
   if(!root)
     return NULL;
   if(strcmp(root->Data ,val) > 0){
     root->left = deletion(root->left, val);
   }
   else if(strcmp(root->Data ,val) < 0){
     root->right = deletion(root->right, val);
   }
   else{
     AVL temp;
     if(root->left == NULL || root->right == NULL){
       if(root->left)
         temp = root->left;
       else if(root->right)
         temp = root->right;
       else
         temp = NULL;
       root = NULL;
       free(root);
       return temp;
     }
     else{
       temp = InorderSuccessorRightTree(root);
       strcpy(root->Data , temp->Data);
       strcpy(root->Synonym , temp->Synonym);
       strcpy(root->Antonym , temp->Antonym);
       int i;
       for (i = 0 ; i < root->CountMeanings; i ++)
       {
           strcpy(root->Meanings[i],temp->Meanings[i]);
       }
       root->right = deletion(root->right,temp->Data);
     }
   }
   if(root){
     //update height
     root->height = maximum(GetHeight(root->left), GetHeight(root->right)) + 1;
     int balance = BalanceT(root);
     if(balance > 1 || balance < -1)
       root = BalanceTree(root);
   }
   return root;
 }



//////////////////////////////////////////////////
///get data from file
/////////////////////////////////////////////////
const char * GetData()
{
    int i = 0;
     char l[50];
    char *x;
    FILE *read;

    read = fopen("Words.txt","r");



    for (i = 0 ; i <= f ; i++)
    {
        fgets(l,250,read);
    }
    f++;

    x = l;
     fclose(read);
    return x;
}
////////////////////////////////////////////////////////////////////////////////////////////
void InorderFirstCharachter(AVL root ,char c){
   if(!root)
     return;
   InorderFirstCharachter(root->left,c);
    if (root->Data[0]== c){
   printf("%s :\n",root->Data);
   int i;
   printf("Meaning(s): ");
   for (i = 0 ; i < root->CountMeanings ; i++)
   printf(" %s ,",root->Meanings[i]);
   printf("Synonym : %s , ",root->Synonym);
   printf("antonym : %s",root->Antonym);

   printf("\n");
    }
   InorderFirstCharachter(root->right,c);
 }


////////////////////////////////////////////////////////////////
// read the tree to hash
////////////////////////////////////////////////////////////////
void ReadTreeInfo(AVL tree)
{
    InOrderHashing(tree);
    int i;//loop variable
    i=0;
    int x;
    x=count;
    SizeOfTable=GetPrime(2*count);//find the first prime >2*count
    Array=(struct HashTable *)malloc(sizeof(struct HashTable )*SizeOfTable);

    for(i=0;i<SizeOfTable;i++)
    {
        Array[i].Tag=0;//empty cells
    }
    for(i=0;i<x;++i){//Insertion

        Hash2Function(HashARR[i],SizeOfTable);
    }
    count=x;
}





/////////////////////////////////////////////////////////////////////////////////////////////
 // get the prime number after n
int GetPrime(int n)
{
    int i1;
int    temp = 1 ;
    int flag=1;
    while(1)
    {
        flag=1;
        for(i1=2;i1<n;i1++)
        {
            if(n%i1 == 0) // if is not prime
            {
                flag=0;
                break;
            }
        }
        if(flag == 1)
            break;
        n++;
    }
    return n;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function to find the index of each record in the hash table
void Hash2Function(char word[100] ,int size)
{ int b = 0;

    int H = StringHash(word) % size;//Hash function

    while(Array[H].Tag == 1)//collision
    {
        b++;
        H = (StringHash(word)+b*b) % size ;
    }
    Array[H].Tag=1;// filled cell
    count++;// element increment
    strcpy(Array[H].Data,word);

}
//////////////////////////////////////////////////////////////////////////////////
int StringHash(char *str){
    unsigned int Hvalue=0;
    while(*str!= '\0')
        Hvalue = Hvalue <<5 + *(str++ );

    return (Hvalue) ;


}
///////////////////////////////////////////////////////////////////////////////
//Function to print the hash function
void HashFunction()
{
    char *s;
    char *A;
    s="%\0";
    printf("\n");
    printf("  H(x) =    Sum str[n-i-1] * 32^i \n");
    printf("  F(x) = ( H(x) + i^2 ) %s SizeOfTable      (collisions)\n",s);
}
///////////////////////////////////////////////////////////////////////////////////
//Function to Insertion a new record to the hash table
void InsertHash(char *word)
{
    if(count>SizeOfTable/2)
        Rehash(SizeOfTable);
    Hash2Function(word,SizeOfTable);
}
////////////////////////////////////////////////////////////////////////////////////
//Function of rehashing
void Rehash(int n)
{
    int i ;
    int kk;
    int j=0;
    int k ;
    int h ;//hash value
    int TempTableSize;
    TempTableSize = GetPrime(2*n);//First prime greater than n
    SizeOfTable = TempTableSize ;
    TempArray=(struct HashTable *)malloc(sizeof(struct HashTable )*TempTableSize);
    for (i = 0; i < TempTableSize; i++)
    {
        TempArray[i].Tag = 0;//initialize the temp list as empty cells
    }
    for (k = 0; k < n; k++)
    {
        if(Array[k].Tag != 1)
        {
            continue;
        }
        //Allocate the record in the temp array
        h = StringHash(Array[k].Data );
        while (TempArray[h].Tag == 1)
        {
            j++;
            h = (StringHash(Array[k].Data) + j*j) % TempTableSize;
        }
        TempArray[h].Tag = 1;
        strcpy(TempArray[h].Data , Array[k].Data);
        count++;
    }
    for (i = 0; i < TempTableSize; i++)
    {
        Array[i].Tag = 0;
    }
    Array=TempArray;
}
//////////////////////////////////////////////////////////////////////////
//Search for a record in the hash table
int SearchInHashed(char* word)
{
     int i;
     i=0;
     int h;
     h=StringHash(word);
     while(Array[h].Tag != 0 && strcmp(Array[h].Data,word)!=0 )
     {
         i++;
         h=(StringHash(word)+i*i)%SizeOfTable;
     }
return h;
}
////////////////////////////////////////////////////////////////

typedef long long ll ; // redefine

int get_key( char *c, int size ) // hash function
{
    ll hv = 1, i =0;
    for(i=0 ; i<strlen(c) ; i++){
        hv = ( ( (hv<<2) + ( (ll)c[i]-60) ) ) ; // equation of hash
        }

    return ((hv%size)+size)%size ; // resize the val
}






//////////////////////////////////////////////////////////////////
//function for printing the in-order of tree
 void InOrderHashing(AVL root){
   if(!root)
     return;
   InOrderHashing(root->left);
   strcpy(HashARR[count],root->Data);
   ++ count ;
   InOrderHashing(root->right);

 }
/////////////////////////////////////////////////////////////
//Function to delete a record from a hash table
void HashDelete(int index)
{
    Array[index].Tag=2;
    count--;
}
///////////////////////////////////////////////////////
int get_prime(int x) // get the prime number after x
{
    int i = 3, temp = 1 ;
    for( ; x<1e9 ; x+=2 )
    {
        for(i=3 ; i*i<=x ; i+=2)
        {
            if(x%i == 0) // if is not prime
            {
                temp =0 ;
                break ;
            }
        }
        if(temp)
            return x ;
        temp =1 ;
    }
    return x ;
}



