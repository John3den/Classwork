#include <stdio.h>
#include <stdlib.h>

int _feof = 0; // что-то feof() не работал, было лень выяснять

typedef struct DictionaryNode {
  char letter;
  int count;
  struct DictionaryNode* branches;
  int numberOfBranches;
} DictionaryNode;

int IsLeaf(DictionaryNode* node){
  if(node->count+1 == node->numberOfBranches)
  {
    return 0;
  }
  return 1;
}

void DictFree(DictionaryNode* node){
  for(int i=0; i < node->numberOfBranches; i++)
  {
    DictFree(node->branches + i);
  }
}

void freeLines(char** lines,int numOfLines){
  for(int i=0;i<numOfLines;i++)
  {
    free(lines[i]);
  }
}

char* ReadLine( FILE* file ) {
  char* string = malloc(sizeof(char));
  int capacity = 1;
  int length = 1;
  char c = getc(file);
  *string = c;
  do
  {
    if(length == capacity)
    {
      capacity*=2;
      string = realloc(string,sizeof(char)*capacity);
    }
    c = getc(file);
    string[length++] = c;
  }while(c != '\n' && c != EOF);
  _feof = (c==EOF) ? 1 : 0;
  string[length-1] = '\0';
  return string;
}

DictionaryNode* DictInsert(char letter,DictionaryNode* node){
  for(int i=0; i < node->numberOfBranches; i++)
  {
    if( letter == node->branches[i].letter )
    {
      node->branches[i].count++;
      return &(node->branches[i]);
    }
  }
  node->numberOfBranches++;
  node->branches = realloc(node->branches, sizeof(DictionaryNode)*(node->numberOfBranches));
  DictionaryNode newBranch;
  newBranch.letter = letter;
  newBranch.count = 1;
  newBranch.branches = malloc(0);
  newBranch.numberOfBranches = 0;
  node->branches[node->numberOfBranches-1] = newBranch;
  return &(node->branches[node->numberOfBranches-1]);
}

void InsertString(char* string, DictionaryNode* root){
  DictionaryNode* current = root;
  do
  {

    current = DictInsert(*string,current);
  }
  while(*(++string));
}

DictionaryNode* CreateDict(char** strings, int numberOfStrings){
  DictionaryNode* root = malloc(sizeof(DictionaryNode));
  root->letter = 0;
  root->count = 0;
  root->branches = malloc(0);
  root->numberOfBranches = 0;
  for(int i =0;i<numberOfStrings;i++)
    InsertString(strings[i],root);
  return root;
}

int ReadFile(FILE* file,char*** lines){
  *lines    = malloc(sizeof(char*));
  *(*lines) = ReadLine(file);
  int capacity      = 1;
  int amountOfLines = 1;
  while(!_feof)
  {
    if(amountOfLines == capacity)
    {
      capacity *= 2;
      *lines = realloc(*lines,sizeof(char*)*capacity);
    }
    (*lines)[amountOfLines++] = ReadLine(file);
  }
  return amountOfLines-1;
}

int BurnString(char* string, DictionaryNode* root){
  DictionaryNode* current = root;
  do
  {
    for(int i=0;i<current->numberOfBranches;i++)
    {
      if(*string == current->branches[i].letter && current->branches[i].count)
      {
        current = current->branches + i;
        current->count--;
        break;
      }
      if(i == current->numberOfBranches - 1)
        return 0;
    }
  }while(*(++string));
  if(!IsLeaf(current))
  {
    // ended up in nonleaf-node, so line was shorter than should be
     return 0;
  }
  return 1;
}

int FileCmp(FILE* f1, FILE* f2){
  int result      = 1;
  char** lines    = malloc(0);
  int numOfLines  = ReadFile(f1,&lines);
  DictionaryNode* lexTree = CreateDict(lines,numOfLines); // строим дерево
  freeLines(lines,numOfLines);
  lines      = realloc(lines,0);
  numOfLines = ReadFile(f2,&lines);
  for(int i=0;i<numOfLines;i++)
  {
    if(!BurnString(lines[i],lexTree))
    {
    result = 0;
    }
  }
  freeLines(lines,numOfLines);
  free(lines);
  DictFree(lexTree);
  return result;
}

void FileCpy(FILE* dst, FILE* src){
  char c;
  while((c = getc(src)) != EOF)
  {
    fprintf(dst,"%c",c);
  }
  return;
}

int main(){
  FILE* f1 = fopen("out.txt", "r");
  FILE* f2 = fopen("in.txt" , "r");
  printf("%i\n",FileCmp(f1,f2));
  fclose(f1);
  fclose(f2);
  return 0;
}
