/**
#include <iostream>
#include <fstream>

using namespace std;

bool ccj[21];

int main()
{
    ifstream f("bac.txt");
    ofstream in("intrebare.txt");
    ofstream r("raspuns.txt");
    ifstream rin("raspuns.txt");
    ofstream rout("raspuns2..txt");
    ofstream c("corect.txt");
    ifstream cor("corect.txt");
    ofstream sgmlt("choose.txt");
    ifstream choo("choose.txt");
    ofstream corecte("corecte2.txt");



    char s[10001],s2[10001],raspuns[21][10001];
    int j,nrintrebare=0,nrraspuns=0,var=0;
    bool ok,ok2,exp;



    while(f.getline(s,10001))
    {

        if(strstr(s,"Explanation")!=NULL)
            while(s[1]!='h' && s[2]!='3')
                f.getline(s, 10001);

        if(strstr(s,"ITE")!=NULL)
            f.getline(s,10001);


        ok=false;
        ok2=false;
        exp=false;
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] == '<') {
                if(strstr(s,"span style=")!=NULL)
                    ok2=true;
                j = i + 1;
                while (s[j] != '>')
                {
                    if(s[j]=='h' && s[j+1]=='3')
                    {
                        ok=true;
                        nrintrebare++;
                    }
                    j++;
                }
                strcpy(s + i, s + j + 1);
                if(strstr(s,"Explanation")!=NULL)
                    exp=true;
                i--;


            }

        }



        if(ok==true)
        {

            nrintrebare--;
            if(nrraspuns!=0)
                in<<nrraspuns<<endl;
            if(nrintrebare!=1)
                for(int i=1;i<=nrraspuns;i++)
                    in<<raspuns[i]<<endl;


            ///bag aici rasppuns
            for(int i=1;i<=nrintrebare;i++)
                if(ccj[i]==true)
                    in<<i<<endl;

            nrraspuns=0;
            if(strlen(s)>1)
            {
                for(int i=1;i<=21;i++)
                    ccj[i]=false;
                in <<nrintrebare << ".";
                in << s << endl;
            }

            //r<<endl<<"],"<<endl<<"[";
            if(strstr(s,"Choose two")!=NULL)
            {var=2;in<<var<<endl;}
            else
            if(strstr(s,"Choose three")!=NULL)
            {var=3;in<<var<<endl;}
            else
            {var=1;in<<var<<endl;}
        }
        else
        {
            if(strlen(s)>=1)
            {
                nrraspuns++;
                strcpy(raspuns[nrraspuns],s);
            }
        }


        if(ok2==true)
            ccj[nrraspuns]=true;


    }
    if(nrintrebare!=1)
        for(int i=1;i<=nrraspuns;i++)
            in<<raspuns[i]<<endl;
    if(nrraspuns!=0)
        in<<nrraspuns<<endl;

    for(int i=1;i<=nrintrebare;i++)
        if(ccj[i]==true)
            in<<i<<endl;



    f.close();
    return 0;



}
*/
#include <iostream>
#include <fstream>

using namespace std;

bool ccj[21];

int main()
{
    ifstream f("bac.txt");
    ofstream in("intrebare.txt");
    ofstream r("raspuns.txt");
    ifstream rin("raspuns.txt");
    ofstream rout("raspuns2..txt");
    ofstream c("corect.txt");
    ifstream cor("corect.txt");
    ofstream sgmlt("choose.txt");
    ifstream choo("choose.txt");
    ofstream corecte("corecte2.txt");



    char s[10001],s2[10001],raspuns[21][10001];
    int j,nrintrebare=0,nrraspuns=0,var=0;
    bool ok,ok2,exp;



    while(f.getline(s,10001))
    {

        if(strstr(s,"Explanation")!=NULL)
            while(s[1]!='h' && s[2]!='3')
                f.getline(s, 10001);

        if(strstr(s,"ITE")!=NULL)
            f.getline(s,10001);
        if(strstr(s,"CCNA")!=NULL)
            f.getline(s,10001);


        ok=false;
        ok2=false;
        exp=false;
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] == '<') {
                if(strstr(s,"span style=")!=NULL)
                    ok2=true;
                j = i + 1;
                while (s[j] != '>')
                {
                    if(s[j]=='h' && s[j+1]=='3')
                    {
                        ok=true;
                        nrintrebare++;
                    }
                    j++;
                }
                strcpy(s + i, s + j + 1);
                if(strstr(s,"Explanation")!=NULL)
                    exp=true;
                i--;


            }

        }



        if(ok==true)
        {

            nrintrebare--;
            if(nrraspuns!=0)
                rout<<nrraspuns<<endl;
            if(nrintrebare!=1)
                for(int i=1;i<=nrraspuns;i++)
                    in<<raspuns[i]<<endl;


            ///bag aici rasppuns
            for(int i=1;i<=nrintrebare;i++)
                if(ccj[i]==true)
                    rout<<i<<endl;


            if(strlen(s)>1 && nrraspuns!=0)
            {
                for(int i=1;i<=21;i++)
                    ccj[i]=false;
                in <<nrintrebare << ".";
                in << s << endl;
            }
            else
                nrintrebare--;
            nrraspuns=0;

            //r<<endl<<"],"<<endl<<"[";
            if(strstr(s,"Choose two")!=NULL)
            {var=2;rout<<var<<endl;}
            else
            if(strstr(s,"Choose three")!=NULL)
            {var=3;rout<<var<<endl;}
            else
            {var=1;rout<<var<<endl;}
        }
        else
        {
            if(strlen(s)>=1)
            {
                nrraspuns++;
                strcpy(raspuns[nrraspuns],s);
            }
        }


        if(ok2==true)
            ccj[nrraspuns]=true;


        /*
        if(strlen(s)>=1)
        {
            if (ok == true)

            /*else
            {
                in<<s<<endl;
                //if(nrraspuns==1)
                  //  r<<char(34)<<s<<char(34);
               // else
                  //  r<<","<<endl<<char(34)<<s<<char(34);

            }

        }*/
    }
    if(nrintrebare!=1)
        for(int i=1;i<=nrraspuns;i++)
            in<<raspuns[i]<<endl;
    if(nrraspuns!=0)
        rout<<nrraspuns<<endl;

    for(int i=1;i<=nrintrebare;i++)
        if(ccj[i]==true)
            rout<<i<<endl;



    /**
    r<<endl<<"]";
    while(rin.getline(s2, 10001))
    {
        if(strstr(s2,"ITE")!=NULL)
            rin.getline(s2,10001);
        if(strstr(s2,"Explanation")!=NULL)
            while(strstr(s2,"]")==NULL)
                rin.getline(s2,10001);
        if(strstr(s2,"\"&nbsp;\"")==NULL)
        rout<<s2<<endl;

    }
     */
    /*
    int x,y;
    while(choo>>x)
    {
        //cout<<x;
        corecte<<"[";
        for(int i=1;i<x;i++)
        {
            cor>>y;
            //cout<<y;
            corecte<<y<<",";
        }
        cor>>y;
        corecte<<y;
        corecte<<"],"<<endl;
    }
     */
    f.close();
    return 0;


}