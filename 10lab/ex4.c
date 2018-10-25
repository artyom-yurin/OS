#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
  FILE *fp;
  fp = fopen("ex4.txt", "w");

  DIR* dirp = opendir("tmp");

  if (dirp == NULL) { return 1;};
  char path[50];
  struct dirent* dirEntry;
  while((dirEntry = readdir(dirp)) != NULL)
  {
      strcpy(path, "tmp/");
      strcat(path, dirEntry->d_name); //construct path tmp/ + name of entry
      struct stat st;
      stat(path, &st); //stats for file with path tmp/ + name of entry
      if(st.st_nlink > 1) // if we have more or equal than 2 links then print all links
      {
        fprintf(fp, "Founded linkes for \"%s\":\n",dirEntry->d_name);
        struct dirent *link;
			  DIR *dirp2 = opendir("tmp"); // find links in tmp folder
			  while((link = readdir(dirp2)) != NULL){
              //link to file have same inodenumber with original file
				      if((link->d_ino == dirEntry->d_ino)){
					           fprintf(fp, "%s ",link->d_name);
				      }
			  }
        fprintf(fp, "\n");
      }
  }
  fclose(fp);
  return 0;
}
