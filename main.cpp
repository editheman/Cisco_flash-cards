#include <iostream>
#include <fstream>

using namespace std;

int menu(int &c)
{
    cout<<"\033[1;30;43m"<<"Choose an option: (1- continue, 0- end)"<<"\033[0m";
    cin>>c;
    if(c!=1)
        return 0;
    else
        return 1;
}


bool ok;
char enunt[100001],raspuns[10][100001];
int nrcorecte,corecte[7],nrraspunsuri,raspunsuri[4],x,c,nr,numaratoare;

int main()
{
    ifstream f("intrebare.txt");
    ifstream g("raspuns2..txt");

    ofstream gresiteint("gresiteenunt.txt");
    ofstream gresitenr("gresiteraspunsuri.txt");

    fstream corecteen("corecteenunt.txt",ios::app);
    fstream corecteras("corecteraspuns.txt",ios::app);



    while(f.getline(enunt,100001))
    {
        ok=true;
        nr++;
        //cout<<"\033[0;30;45m"<<enunt<<"\033[0m"<<endl<<endl;
        for(int i=0;i<strlen(enunt);i++)
        {
            cout<<"\033[0;30;45m"<<enunt[i]<<"\033[0m";
            numaratoare++;
            if(numaratoare>145 && strchr(" ",enunt[i])!=NULL)
            {
                cout << endl;
                numaratoare = 0;
            }

        }
        cout<<endl;
        g>>nrcorecte>>nrraspunsuri;

        for(int i=1;i<=nrraspunsuri;i++)
        {
            f.getline(raspuns[i], 100001);
            cout<<"\033[7;44;30m"<<i<<"\033[0m"<<" "<<raspuns[i]<<endl;
        }

        for(int i=1;i<=nrcorecte;i++)
        {
            g>>x;
            corecte[i]=x;
        }
        for(int i=1;i<=nrcorecte;i++)
        {
            cout<<"\033[0;30;47m"<<"Raspunsul dumneavoastra este:"<<"\033[0m"<<" ";
            cin>>raspunsuri[i];
        }

        for(int i=1;i<=nrcorecte;i++)
        {
            if(corecte[i]!=raspunsuri[i])
            {
                ok=false;
                if(i==1)
                    cout<<"\033[1;31mRaspunsul corect este cel cu nr: \033[0m"<<"\033[0;31;40m"<<corecte[i]<<"\033[0m"<<endl;
                else
                    cout<<"\033[1;31mCel de-al "<<i<<"-lea raspuns corect este: \033[0m"<<"\033[0;31;40m"<<corecte[i]<<"\033[0m"<<endl;

            }
        }
        if(ok==true)
        {
            cout<<endl<<"\033[1;30;42m"<<"Corect!"<<"\033[0m"<<endl;
            corecteen<<enunt<<endl;
            for(int i=1;i<=nrraspunsuri;i++)
                corecteen<<raspuns[i]<<endl;
            corecteras << nrcorecte << endl << nrraspunsuri << endl;
            for(int i=1;i<=nrcorecte;i++)
                corecteras<<corecte[i]<<endl;
        }
        cout<<endl;

        ///ai gresit intrebarea
        if(ok==false)
        {

            gresiteint << enunt << endl;
            for (int i = 1; i <= nrraspunsuri; i++)
                gresiteint << raspuns[i] << endl;
            gresitenr << nrcorecte << endl << nrraspunsuri << endl;
            for (int i = 1; i <= nrcorecte; i++)
                gresitenr << corecte[i] << endl;
            cout << endl;
        }





        ///calling the menu function
        if(nr%5==0)
            if(menu(c)==0)
            {
                ///completare probleme gresite
                ifstream gresiteenre("gresiteenunt.txt");
                ifstream gresiterasre("gresiteraspunsuri.txt");

                while(f.getline(enunt,100001))
                    gresiteint<<enunt<<endl;
                while(g>>x)
                    gresitenr<<x<<endl;

                ///rescriere fisier initial
                ofstream fout("intrebare.txt");
                ofstream goutt("raspuns2..txt");

                while(gresiteenre.getline(enunt,100001))
                    fout<<enunt<<endl;
                while(gresiterasre>>x)
                    goutt<<x<<endl;

                return 0;
            }
    }
    f.close();
    g.close();
    gresitenr.close();
    gresiteint.close();
    return 0;

}