function rand(awal,akhir){
return Math.floor(Math.random()*(akhir-awal))+awal;
}
function range(size,startAt=0){
return [...Array(size).keys()].map(i => i + startAt);
}
//masalah di akhir (list ke98) "!" akan di decode menjadi "a"(list ke0)
const alph = "q?+elP53h4pfL_b:kQ/rZBmg9sj;HUvnXR=JNDEW8KoTG2iSMc67YI#xzFdaACVw-1!0tOyu.";

        function zencode(kata, sandi=1){
                encode = "";
                test ="";
                for(i in range(kata.length)){
                        xxx = rand(0,alph.length-2);
                        xxy = xxx % 6;
                        encode += alph[xxx];
                        for(ii in range(xxy)){encode += alph[rand(0,alph.length-2)];}
                        if(kata[i] == " "){
                                encode += "$";
                        }else{
                                ang = 0;
                                for(xx in range(alph.length)){
                                        if(kata[i] == alph[xx]){ang = xx;}}
                                bng = alph.length-ang-1;
                                cng = bng + xxy;
                                if(cng > alph.length-1){cng -= alph.length-1;}
                                encode += alph[cng];
                                test += alph[cng];}}
                encode += "##";
                return encode;}

        function zdecode(code){
                skr = 0;
                kata = "";
                while(skr < code.length-2){
                        lanjut = 0;
                        for(a in range(alph.length)){
                                if(code[skr] == alph[a]){
                                        lanjut = a % 6;}}
                        skr += lanjut+1;
                        for(xx in range(alph.length)){
                                if(code[skr] == alph[xx]){ang = xx;
                                }else if(code[skr] == "$"){ang = 24802;}}
                        cng = ang - lanjut;
                        if(cng < 0){cng += alph.length-1;}
                        bng = alph.length-cng-1;
                        if(ang == lanjut){bng =0;}
                        if(ang == 24802){ kata += " ";}else{ kata += alph[bng];}
                        skr+=1;}
                return kata;}