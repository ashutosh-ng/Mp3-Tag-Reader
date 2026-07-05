#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edit.h"

int convert_syncsafe(unsigned char bytes[4])
{
    return ((bytes[0]&0x7F)<<21) |
            ((bytes[1]&0x7F)<<14) |
            ((bytes[2]&0x7F)<<7)  |
            (bytes[3]&0x7F);
}
//function to convert big endian 4 bytes to integer
int convert_big_endian(unsigned char bytes[4])
{
    return (bytes[0]<<24) |
           (bytes[1]<<16) |
           (bytes[2]<<8)  |
           (bytes[3]);
} 
//function to read and display mp3 tag info
void view_tags(const char *filename)
{
    FILE *fp=fopen(filename,"rb");
    if(fp==NULL)
    {
        printf("Error: Cannot open %s\n", filename);
        return;
    }
    fseek(fp,10,SEEK_SET); // skip 10 byte header
    for(int i=0;i<6;i++)
    {
        char Tag[5];
        fread(Tag,4,1,fp);
        Tag[4]='\0';
        if(Tag[0]==0)
        break;

        unsigned char size_bytes[4];
        fread(size_bytes,4,1,fp);
        int size=convert_big_endian(size_bytes);

        fseek(fp,2,SEEK_CUR); //skip 2 byte frame flag

        char content[size+1];
        fread(content,size,1,fp);
        content[size]='\0';

        //display based on tag name
         if (strcmp(Tag,"TIT2")==0)
            printf("Title : %s\n",content+1);
        else if (strcmp(Tag,"TPE1")==0)
            printf("Artist: %s\n",content+1);
        else if (strcmp(Tag,"TALB")==0)
            printf("Album : %s\n",content+1);
        else if (strcmp(Tag,"TYER")==0)
            printf("Year  : %s\n",content+1);
        else if (strcmp(Tag,"TCON")==0)
            printf("Genre : %s\n",content+1);
        else if (strcmp(Tag,"COMM")==0)
            printf("Comment: %s\n",content+4);
        else
            printf("%s : %s\n",Tag,content+1);
    }
    fclose(fp);
}
//function to modify given tag with new value
void edit_tags(const char *filename)
{
    char tag_name[5], new_value[100];
    printf("Enter tag to edit (TIT2/TPE1/TALB/TYER/TCON/COMM): ");
    scanf("%s",tag_name);
    printf("Enter new value: ");
    scanf(" %[^\n]",new_value);

    FILE *src=fopen(filename,"rb");
    if(src==NULL)
    {
        printf("File not found!\n");
        return;
    }

    FILE *temp=fopen("temp.mp3","wb");
    if(temp==NULL)
    {
        printf("Error creating temporary file!\n");
        fclose(src);
        return;
    }

    unsigned char header[10];
    fread(header,1,10,src);
    fwrite(header,1,10,temp);

    while(1)
    {
        char Tag[5];
        if(fread(Tag,1,4,src)!=4)
            break;
        Tag[4]='\0';
        if(Tag[0]==0)
            break;

        unsigned char size_bytes[4];
        fread(size_bytes,1,4,src);
        int size=convert_big_endian(size_bytes);

        unsigned char flags[2];
        fread(flags,1,2,src);

        char content[size];
        fread(content,1,size,src);
        //if current frame matches tag user wants to edit
        if(strcmp(Tag,tag_name)==0)
        {
            int new_size=strlen(new_value)+1;
            unsigned char new_size_bytes[4];
            new_size_bytes[0]=(new_size>>24)&0xFF;
            new_size_bytes[1]=(new_size>>16)&0xFF;
            new_size_bytes[2]=(new_size>>8)&0xFF;
            new_size_bytes[3]=new_size&0xFF;

            fwrite(Tag,1,4,temp);
            fwrite(new_size_bytes,1,4,temp);
            fwrite(flags,1,2,temp);
            fputc(0,temp);
            fwrite(new_value,1,strlen(new_value),temp);
        }
        else
        {
            fwrite(Tag,1,4,temp);
            fwrite(size_bytes,1,4,temp);
            fwrite(flags,1,2,temp);
            fwrite(content,1,size,temp);
        }
    }
     //copy remaining bytes if any
    int c;
    while((c=fgetc(src))!=EOF)
        fputc(c,temp);

    fclose(src);
    fclose(temp);

    remove(filename);
    rename("temp.mp3",filename);

    printf("Tag updated successfully!\n");
}

