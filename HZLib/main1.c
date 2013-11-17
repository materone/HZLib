//
//  main.c
//  HZLib
//
//  Created by tony on 13-11-16.
//  Copyright (c) 2013Äê tony. All rights reserved.
//

#include <stdio.h>



int convone()
{
    FILE* fphzk = NULL;
    int i, j, k, offset;
    int flag;
    unsigned char buffer[32];
    unsigned char word[3] = "Ì·";
    unsigned char key[8] = {
        0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
    };
    
    fphzk = fopen("/bak/HZK16", "rb");
    if(fphzk == NULL){
        fprintf(stderr, "error hzk16\n");
        return 1;
    }
    offset = (94*(unsigned int)(word[0]-0xa0-1)+(word[1]-0xa0-1))*32;
    fseek(fphzk, offset, SEEK_SET);
    fread(buffer, 1, 32, fphzk);
    for(k=0; k<32; k++){
        printf("%02X ", buffer[k]);
    }
    printf("\n");
    for(k=0; k<16; k++){
        for(j=0; j<2; j++){
            for(i=0; i<8; i++){
                flag = buffer[k*2+j]&key[i];
                printf("%s", flag?"¡ñ":"¡ð");
            }
        }
        printf("\n");
    }
    fclose(fphzk);
    fphzk = NULL;
    return 0;
}

int conv(){
         FILE* fphzk = NULL;
        int i, j, k, offset;
        int flag;
    unsigned char buffer[32];
    unsigned char word[5] = "Ì·";
        unsigned char word1[5] = "Ì·";
        unsigned char key[8] = {
            0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01
        };
        fphzk = fopen("/bak/HZK16", "rb");
        if(fphzk == NULL){
            fprintf(stderr, "error hzk16\n");
            return 1;
        }
        while(1){
            printf("Please input HZ:");
            for(;;){
                fgets((char*)word, 5, stdin);
                //word = "Ì·";
                //*word = "Ì·";
                if(*word == '\n')
                    break;
                offset = (94*(unsigned int)(word[0]-0xa0-1)+(word[1]-0xa0-1))*32;
                fseek(fphzk, offset, SEEK_SET);
                fread(buffer, 1, 32, fphzk);
                for(k=0; k<16; k++){
                    for(j=0; j<2; j++){
                        for(i=0; i<8; i++){
                            flag = buffer[k*2+j]&key[i];
                            printf("%s", flag?"¡ñ":"¡ð");
                        }
                    }
                    printf("\n");
                }
                printf("uchar code key[32] = {");
                for(k=0; k<31; k++){
                    printf("0x%02X,", buffer[k]);
                }
                printf("0x%02X};\n", buffer[31]);
                printf("\n");
            }
        }
        fclose(fphzk);
        fphzk = NULL;
        return 0;
    }

int main(int argc, const char * argv[])
{

    // insert code here...
    printf("Hello, World!\n");
    convone();
    conv();
    return 0;
}



