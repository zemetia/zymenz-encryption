#include "zymenz.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int randX(int x, int y){
	return rand() % (y-x) + x;
}

string zymenz::zencode(string kata){
    string encode = "";
    string test ="";
        for(int i; i<kata.length(); i++){
            int xxx = randX(0,zymenz::alph.length()-2);
            int xxy = xxx % 6;
            encode += alph[xxx];
            for(int ii; ii<xxy;i++){encode += zymenz::alph[randX(0,zymenz::alph.length()-2)];}
            if(kata[i] == ' '){
                encode += "$";
            }else{
                int ang = 0;
                for(int xx; xx<zymenz::alph.length();xx++){
                    if(kata[i] == zymenz::alph[xx]){ang = xx;}}
                int bng = zymenz::alph.length()-ang-1;
                int cng = bng + xxy;
            	if(cng > zymenz::alph.length()-1){cng -= zymenz::alph.length()-1;}
                encode += zymenz::alph[cng];
                test += zymenz::alph[cng];}}
    encode += "##";
    cout<<encode;
	return encode;}
	
string zymenz::zdecode(string code){
                int skr = 0;
                string kata = "";
                while(skr < code.length()-2){
                        int lanjut = 0;
                        for(int a; a<zymenz::alph.length();a++){
                                if(code[skr] == zymenz::alph[a]){
                                        lanjut = a % 6;}}
                        skr += lanjut+1;
                        int ang;
                        for(int xx; xx<zymenz::alph.length();xx++){
                                if(code[skr] == zymenz::alph[xx]){ang = xx;
                                }else if(code[skr] == '$'){ang = 24802;}}
                        int cng = ang - lanjut;
                        if(cng < 0){cng += zymenz::alph.length()-1;}
                        int bng = zymenz::alph.length()-cng-1;
                        if(ang == lanjut){bng =0;}
                        if(ang == 24802){ kata += " ";}else{ kata += zymenz::alph[bng];}
                        skr+=1;}
                return kata;}

