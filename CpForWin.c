#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
   if (argc<3)
   {
     return 1;
   }
  FILE *srcFP=fopen(argv[1],"rb");
  if(srcFP==NULL)
   {
    return 2;
   }
  FILE *dstFP=fopen(argv[2],"wb");
  if(dstFP==NULL)
  {
   return 3;
  }
  char buf[100];

 while( fread(buf,sizeof(char),sizeof(buf),srcFP)!=0)
   {
     fwrite(buf,sizeof(char),sizeof(buf),dstFP);
   }
  fclose(srcFP);
  fclose(dstFP);
  
  return 0;

}
