#ifndef EDIT_H
#define EDIT_H

void view_tags(const char *filename);
void edit_tags(const char *filename);
int convert_syncsafe(unsigned char bytes[4]);
int convert_big_endian(unsigned char bytes[4]);


#endif
