#include<unistd.h>
#include<fcntl.h>
int main (int argc,char **argv)
{
  if (argc<3)
    {
      return 1;
    }
  
   int FdSrc=open(argv[1],O_RDONLY);
    if(FdSrc==-1)
     {
       return 2;
     }
  int FdDst=open(argv[2], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
   if(FdDst==-1)
    {
     return 3;
    }
  char buf[100];
  ssize_t CharCnt;
  
    while((CharCnt = read(FdSrc,buf,sizeof(buf)))!=0)
   {
     write(FdDst,buf,CharCnt);
   }
   return 0;
}
