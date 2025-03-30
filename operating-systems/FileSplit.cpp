//Anhelina Belavezha
#include <unistd.h>  
#include <fcntl.h>                                               

/*
Here is the function int podziel(const char *s) in C++ that reads a file specified by the parameter s and splits it into two "halves", 
saving them into files named fragment1 and fragment2. If the length of the file (in bytes) is even,
the two fragments will have equal lengths. If the length is odd, the first fragment will be one byte longer than the second. 
In any case, the concatenation of the two fragments will correspond to the original file. 
The function returns 0 if successful and -1 if any error occurs. 
The files fragment1 and fragment2 should be created or cleared if they already exist. 
The code should use system calls such as open, read, write, etc.; no operations from stdio or iostream libraries are allowed.
*/

int podziel(const char *file) {
    int input = open(file, O_RDONLY);
    int output1 = open("fragment1", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int output2 = open("fragment2", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if(input == -1) return -1;
    if(output1 == -1) return -1;
    if(output2 == -1) return -1;

    int size = 0;
    char buf[1];
    int bytes = 1;
    int newbyte = 0;

    while(bytes > 0) {                                          
        bytes = read(input, buf, 1);
        size += bytes;
        if(bytes == -1)return -1;
    }

    close(input);
    input = open(file, O_RDONLY);

    if(size % 2 == 0) {                                         
        while(newbyte < size) {
            if(size/2 > newbyte) {
                bytes = read(input, buf, 1);
                if(bytes <= 0)
                    return -1;
                if(bytes == -1)
                    return -1;
                write(output1, buf, bytes);
                newbyte += bytes;
            }
            else {
                bytes = read(input, buf, 1);
                if(bytes <= 0)
                    return -1;
                if(bytes == -1)
                    return -1;
                write(output2, buf, bytes);
                newbyte += bytes;}}}
    else {                                                      
        while(newbyte < size) {
            if(size/2 + 1 <= newbyte) {
                bytes = read(input, buf, 1);
                if(bytes <= 0)
                    return -1;
                if(bytes == -1)
                    return -1;
                write(output2, buf, bytes);
                newbyte += bytes;}
            else {
                bytes = read(input, buf, 1);
                if(bytes <= 0)
                    return -1;
                if(bytes == -1)
                    return -1;
                write(output1, buf, bytes);
                newbyte += bytes;}}}

    close(input);
    close(output1);
    close(output2);
    return 0;
}
/*
int main() {
const char* file = "input.txt"; 
int result = podziel(file);
return 0;
}*/
