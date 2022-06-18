#include <iostream>
#include <time.h>
using namespace std;
class Scoreboard
{
    public:
    int totalrun,wicket;
    int over;
    Scoreboard()
    {
    }
    void ShowScore(int x,int y,int z)
    {
        totalrun=x;
        wicket=y;
        over=z;
        cout<<"Total : "<<totalrun<<" "<<"Wicket: "<<wicket<<" "<<"Over  : "<<over<<endl;
    }
};
class Player
{
    public:
    string Name;
    int innings,runs,highscore,gaveruns;
    double battingaverage,strikerate,bowlingaverage;
    int hundreds;
    int age;
    int howmanybowlsbatted,howmanybowlsbowled;
    int bowlinginnings,wickets;
    int azkkotorun=0;
    int azkkotowicket=0;
    int azkkotokhaise=0;
    int azkkotoballbattingkorse=0;
    int azkkotooverbowlingkorse=0;
    int azkotowicketpaise=0;
};
class Cricket
{
    public:
    Scoreboard scores;
    Player teamAplayers[12],teamBplayers[12];
    bool teamAplayersout[12]={false},teamBplayersout[12]={false};
    int currentfirstplayerAbatting=0,currentsecondplayerAbatting=1;
    int currentfirstplayerBbatting=0,currentsecondplayerBbatting=1;
    int currentAbowling=0,currentBbowling=0;
    int totalrunfirstinningsA=0,totalrunfirstinningsB=0;
    int totalrunsecondinningsA=0,totalrunsecondinningsB=0;
};
Cricket x;
void simulate()
{
        srand(time(0));
        cout<<"Innings "<<1<<endl;
        cout<<"Team A Batting"<<endl;
        int wickets=10;
        int over=1;
        x.currentfirstplayerAbatting=0,x.currentsecondplayerAbatting=1;//First Two are taken
        x.teamAplayersout[x.currentfirstplayerAbatting]=true;
        x.teamAplayersout[x.currentsecondplayerAbatting]=true;
        while(over<=10&&wickets>0){
                while(true){
                    int pp=rand()%12;
                    if(pp!=x.currentBbowling){
                        x.currentBbowling=pp;
                        break;
                    }
                }
                x.teamBplayers[x.currentBbowling].azkkotooverbowlingkorse++;//
                for(int bowl=1;bowl<=6;bowl++){
                    int xx=rand()%6;
                    x.teamBplayers[x.currentBbowling].azkkotokhaise+=xx;
                    if(xx==5){
                        bowl--;
                        continue;
                    }
                    if(xx==0){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                    }
                    else if(xx==1){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun++;
                        swap(x.currentfirstplayerAbatting,x.currentsecondplayerAbatting);
                        x.totalrunfirstinningsA+=1;
                    }
                    else if(xx==2){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun+=2;
                    }
                    else if(xx==3){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun+=3;
                        x.totalrunfirstinningsA+=3;
                        swap(x.currentfirstplayerAbatting,x.currentsecondplayerAbatting);
                    }
                    else if(xx==4){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun+=4;
                        x.totalrunfirstinningsA+=4;
                    }
                    else if(xx==6){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun+=6;
                        x.totalrunfirstinningsA+=6;
                    }
                    else if(xx==7){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentBbowling].azkkotowicket++;
                        wickets--;
                        if(wickets==0)break;
                        for(int jj=0;jj<11;jj++){
                            if(x.teamAplayersout[jj]==false){
                                x.currentfirstplayerAbatting=jj;
                                break;
                            }
                        }
                    }
                }
                swap(x.currentfirstplayerAbatting,x.currentsecondplayerAbatting);
                x.scores.ShowScore((int)x.totalrunfirstinningsA,abs(10-wickets),(int)over);
                over++;
        }
        wickets=10;
        over=1;
        x.currentfirstplayerBbatting=0,x.currentsecondplayerBbatting=1;
        x.teamBplayersout[x.currentfirstplayerBbatting]=true;
        x.teamBplayersout[x.currentsecondplayerBbatting]=true;
        cout<<"Team B Batting"<<endl;
        while(over<=10&&wickets>0){
                while(true){
                    int pp=rand()%12;
                    if(pp!=x.currentAbowling){
                        x.currentBbowling=pp;
                        break;
                    }
                }
                x.teamAplayers[x.currentAbowling].azkkotooverbowlingkorse++;
                for(int bowl=1;bowl<=6;bowl++){
                    int xx=rand()%8;
                    x.teamAplayers[x.currentBbowling].azkkotokhaise+=xx;
                    if(xx==5){
                        bowl--;
                        continue;
                    }
                    if(xx==0){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                    }
                    else if(xx==1){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun++;
                        swap(x.currentfirstplayerBbatting,x.currentsecondplayerBbatting);
                        x.totalrunfirstinningsB+=1;
                    }
                    else if(xx==2){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun+=2;
                    }
                    else if(xx==3){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun+=3;
                        x.totalrunfirstinningsB+=3;
                        swap(x.currentfirstplayerBbatting,x.currentsecondplayerBbatting);
                    }
                    else if(xx==4){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun+=4;
                        x.totalrunfirstinningsB+=4;
                    }
                    else if(xx==6){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun+=6;
                        x.totalrunfirstinningsB+=6;
                    }
                    else if(xx==7){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentBbowling].azkkotowicket++;
                        wickets--;
                        if(wickets==0)break;
                        for(int jj=0;jj<11;jj++){
                            if(x.teamBplayersout[jj]==false){
                                x.currentfirstplayerBbatting=jj;
                                break;
                            }
                        }
                    }
                }
                swap(x.currentfirstplayerBbatting,x.currentsecondplayerBbatting);
                x.scores.ShowScore((int)x.totalrunfirstinningsB,abs(10-wickets),(int)over);
                over++;
        }
        cout<<"After First Innings"<<endl;
        cout<<"Team A scored : "<<x.totalrunfirstinningsA<<endl;
        cout<<"Team B scored : "<<x.totalrunfirstinningsB<<endl<<endl;
        cout<<"Innings "<<2<<endl;
        wickets=10;
        over=1;
        x.currentfirstplayerAbatting=0,x.currentsecondplayerAbatting=1;
        x.teamAplayersout[x.currentfirstplayerAbatting]=true;
        x.teamAplayersout[x.currentsecondplayerAbatting]=true;
        while(over<=10&&wickets>0){
                while(true){
                    int pp=rand()%12;
                    if(pp!=x.currentBbowling){
                        x.currentBbowling=pp;
                        break;
                    }
                }
                x.teamBplayers[x.currentBbowling].azkkotooverbowlingkorse++;
                for(int bowl=1;bowl<=6;bowl++){
                    int xx=rand()%8;
                    x.teamBplayers[x.currentBbowling].azkkotokhaise+=xx;
                    if(xx==5){
                        bowl--;
                        continue;
                    }
                    if(xx==0){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                    }
                    else if(xx==1){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun++;
                        swap(x.currentfirstplayerAbatting,x.currentsecondplayerAbatting);
                        x.totalrunsecondinningsA+=1;
                    }
                    else if(xx==2){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun+=2;
                    }
                    else if(xx==3){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun+=3;
                        x.totalrunsecondinningsA+=3;
                        swap(x.currentfirstplayerAbatting,x.currentsecondplayerAbatting);
                    }
                    else if(xx==4){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun+=4;
                        x.totalrunsecondinningsA+=4;
                    }
                    else if(xx==6){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotorun+=6;
                        x.totalrunsecondinningsA+=6;
                    }
                    else if(xx==7){
                        x.teamAplayers[x.currentfirstplayerAbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentBbowling].azkkotowicket++;
                        wickets--;
                        if(wickets==0)break;
                        for(int jj=0;jj<11;jj++){
                            if(x.teamAplayersout[jj]==false){
                                x.currentfirstplayerAbatting=jj;
                                break;
                            }
                        }
                    }
                }
                swap(x.currentfirstplayerAbatting,x.currentsecondplayerAbatting);
                x.scores.ShowScore((int)x.totalrunsecondinningsA,abs(10-wickets),(int)over);
                over++;
        }
        wickets=10;
        over=1;
        x.currentfirstplayerBbatting=0,x.currentsecondplayerBbatting=1;
        x.teamBplayersout[x.currentfirstplayerBbatting]=true;
        x.teamBplayersout[x.currentsecondplayerBbatting]=true;
        cout<<"Team B Batting"<<endl;
        while(over<=10&&wickets>0){
                while(true){
                    int pp=rand()%12;
                    if(pp!=x.currentAbowling){
                        x.currentBbowling=pp;
                        break;
                    }
                }
                x.teamAplayers[x.currentAbowling].azkkotooverbowlingkorse++;
                for(int bowl=1;bowl<=6;bowl++){
                    int xx=rand()%8;
                    x.teamAplayers[x.currentBbowling].azkkotokhaise+=xx;
                    if(xx==5){
                        bowl--;
                        continue;
                    }
                    if(xx==0){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                    }
                    else if(xx==1){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun++;
                        swap(x.currentfirstplayerBbatting,x.currentsecondplayerBbatting);
                        x.totalrunsecondinningsB+=1;
                    }
                    else if(xx==2){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun+=2;
                    }
                    else if(xx==3){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun+=3;
                        x.totalrunsecondinningsB+=3;
                        swap(x.currentfirstplayerBbatting,x.currentsecondplayerBbatting);
                    }
                    else if(xx==4){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun+=4;
                        x.totalrunsecondinningsB+=4;
                    }
                    else if(xx==6){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotorun+=6;
                        x.totalrunsecondinningsB+=6;
                    }
                    else if(xx==7){
                        x.teamBplayers[x.currentfirstplayerBbatting].azkkotoballbattingkorse++;
                        wickets--;
                        x.teamAplayers[x.currentBbowling].azkkotowicket++;
                        if(wickets==0)break;
                        for(int jj=0;jj<11;jj++){
                            if(x.teamBplayersout[jj]==false){
                                x.currentfirstplayerBbatting=jj;
                                break;
                            }
                        }
                    }
                }
                swap(x.currentfirstplayerBbatting,x.currentsecondplayerBbatting);
                x.scores.ShowScore((int)x.totalrunsecondinningsB,abs(10-wickets),(int)over);
                over++;
        }
        cout<<"After Second Innings"<<endl;
        cout<<"Team A scored : "<<x.totalrunsecondinningsA<<endl;
        cout<<"Team B scored : "<<x.totalrunsecondinningsB<<endl<<endl;
}
int main()
{
    ///Here We assigned the information of all the players of both teams Manually///
    freopen("input.txt","r",stdin);//Take input from team A
    for(int i=0;i<11;i++){
        cin>>x.teamAplayers[i].Name;
        cin>>x.teamAplayers[i].age;
        cin>>x.teamAplayers[i].innings;
        cin>>x.teamAplayers[i].runs>>x.teamAplayers[i].gaveruns;
        cin>>x.teamAplayers[i].highscore;
        cin>>x.teamAplayers[i].howmanybowlsbatted;
        cin>>x.teamAplayers[i].wickets;
        cin>>x.teamAplayers[i].hundreds;
        cin>>x.teamAplayers[i].howmanybowlsbowled;
        x.teamAplayers[i].strikerate=((double)x.teamAplayers[i].runs/x.teamAplayers[i].howmanybowlsbatted)*100;
        x.teamAplayers[i].battingaverage=(double)x.teamAplayers[i].runs/x.teamAplayers[i].innings;
        x.teamAplayers[i].bowlingaverage=(double)x.teamAplayers[i].gaveruns/x.teamAplayers[i].innings;
    }
    for(int i=0;i<11;i++)//team b
        {
        cin>>x.teamBplayers[i].Name;
        cin>>x.teamBplayers[i].age;
        cin>>x.teamBplayers[i].innings;
        cin>>x.teamBplayers[i].runs>>x.teamBplayers[i].gaveruns;
        cin>>x.teamBplayers[i].highscore;
        cin>>x.teamBplayers[i].howmanybowlsbatted;
        cin>>x.teamBplayers[i].wickets;
        cin>>x.teamBplayers[i].hundreds;
        cin>>x.teamBplayers[i].howmanybowlsbowled;
        x.teamBplayers[i].strikerate=(double)x.teamBplayers[i].runs/x.teamBplayers[i].innings;
        x.teamBplayers[i].battingaverage=(double)x.teamBplayers[i].runs/x.teamBplayers[i].innings;
        x.teamBplayers[i].bowlingaverage=(double)x.teamBplayers[i].gaveruns/x.teamBplayers[i].innings;
    }
    cout<<"BEFORE THE GAME LETS TAKE A LOOK AT THE INFORMATIONS OF THE PLAYERS"<<endl;
    cout<<"********************************************************************"<<endl;
    cout<<"TEAM A"<<endl;
    for(int i=0;i<11;i++){
        cout<<"Name :"<<x.teamAplayers[i].Name<<endl;
        cout<<"Age  :"<<x.teamAplayers[i].age<<endl;
        cout<<"Innings:"<<x.teamAplayers[i].innings<<endl;
        cout<<"*************************************"<<endl;
        cout<<"BATTING INFORMATION"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"Runs : "<<x.teamAplayers[i].runs<<endl;
        cout<<"High Score: "<<x.teamAplayers[i].highscore<<endl;
        cout<<"Average: "<<x.teamAplayers[i].battingaverage<<endl;
        cout<<"Strike Rate: "<<x.teamAplayers[i].strikerate<<endl;
        cout<<"Hundreds: "<<x.teamAplayers[i].hundreds<<endl;
        cout<<"BOWLING INFORMATION"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"Wickets : "<<x.teamAplayers[i].wickets<<endl;
        cout<<"Bowling Average : "<<x.teamAplayers[i].bowlingaverage<<endl<<endl;;
    }
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"TEAM B"<<endl;
    for(int i=0;i<11;i++){
        cout<<"Name :"<<x.teamBplayers[i].Name<<endl;
        cout<<"Age  :"<<x.teamBplayers[i].age<<endl;
        cout<<"Innings:"<<x.teamBplayers[i].innings<<endl;
        cout<<"*************************************"<<endl;
        cout<<"BATTING INFORMATION"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"Runs : "<<x.teamBplayers[i].runs<<endl;
        cout<<"High Score: "<<x.teamBplayers[i].highscore<<endl;
        cout<<"Average: "<<x.teamBplayers[i].battingaverage<<endl;
        cout<<"Strike Rate: "<<x.teamBplayers[i].strikerate<<endl;
        cout<<"Hundreds: "<<x.teamBplayers[i].hundreds<<endl;
        cout<<"BOWLING INFORMATION"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"Wickets : "<<x.teamBplayers[i].wickets<<endl;
        cout<<"Bowling Average : "<<x.teamBplayers[i].bowlingaverage<<endl<<endl<<endl;
    }
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"                LET THE GAME BEGIN"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    simulate();
    cout<<"********************************************************"<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"TEAM A TOTAL SCORED IN THESE TWO INNINGS:"<<x.totalrunfirstinningsA+x.totalrunsecondinningsA<<endl;
    cout<<"TEAM B TOTAL SCORED IN THESE TWO INNINGS:"<<x.totalrunfirstinningsB+x.totalrunsecondinningsB<<endl;
    if(x.totalrunfirstinningsA+x.totalrunsecondinningsA>x.totalrunfirstinningsB+x.totalrunsecondinningsB){
        cout<<"Team A wins"<<endl;
    }
    else if(x.totalrunfirstinningsA+x.totalrunsecondinningsA<x.totalrunfirstinningsB+x.totalrunsecondinningsB){
        cout<<"Team B wins"<<endl;
    }
    else{
        cout<<"The series is a draw"<<endl;
    }
     for(int i=0;i<11;i++)// TEAM A PLAYERS UPDATED VALUE
        {
        x.teamAplayers[i].gaveruns+=x.teamAplayers[i].azkkotokhaise;
        x.teamAplayers[i].howmanybowlsbatted+=x.teamAplayers[i].azkkotoballbattingkorse;
        x.teamAplayers[i].howmanybowlsbowled+=(x.teamAplayers[i].azkkotooverbowlingkorse*6);
        x.teamAplayers[i].innings+=2;
        x.teamAplayers[i].runs+=x.teamAplayers[i].azkkotorun;
        x.teamAplayers[i].strikerate=(((double)x.teamAplayers[i].runs)/x.teamAplayers[i].howmanybowlsbatted)*100;
        x.teamAplayers[i].battingaverage=((double)x.teamAplayers[i].runs)/x.teamAplayers[i].innings;
        x.teamAplayers[i].bowlingaverage=((double)x.teamAplayers[i].gaveruns)/x.teamAplayers[i].innings;
    }
    for(int i=0;i<11;i++)//TEAM B PLAYERS UPDATED VALUE
        {
        x.teamBplayers[i].gaveruns+=x.teamBplayers[i].azkkotokhaise;
        x.teamBplayers[i].howmanybowlsbatted+=x.teamBplayers[i].azkkotoballbattingkorse;
        x.teamBplayers[i].howmanybowlsbowled+=(x.teamBplayers[i].azkkotooverbowlingkorse*6);
        x.teamBplayers[i].innings+=2;
        x.teamBplayers[i].runs+=x.teamBplayers[i].azkkotorun;
        x.teamBplayers[i].strikerate=(((double)x.teamBplayers[i].runs)/x.teamBplayers[i].howmanybowlsbatted)*100;
        x.teamBplayers[i].battingaverage=((double)x.teamBplayers[i].runs)/x.teamBplayers[i].innings;
        x.teamBplayers[i].bowlingaverage=((double)x.teamBplayers[i].gaveruns)/x.teamBplayers[i].innings;
    }
    cout<<"AFTER THE GAME LETS TAKE A LOOK AT THE INFORMATIONS OF THE PLAYERS"<<endl;
    cout<<"********************************************************************"<<endl;
    cout<<"TEAM A"<<endl;
    for(int i=0;i<11;i++){
        cout<<"Name :"<<x.teamAplayers[i].Name<<endl;
        cout<<"Age  :"<<x.teamAplayers[i].age<<endl;
        cout<<"Innings:"<<x.teamAplayers[i].innings<<endl;
        cout<<"*************************************"<<endl;
        cout<<"BATTING INFORMATION"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"Runs : "<<x.teamAplayers[i].runs<<endl;
        cout<<"High Score: "<<x.teamAplayers[i].highscore<<endl;
        cout<<"Average: "<<x.teamAplayers[i].battingaverage<<endl;
        cout<<"Strike Rate: "<<x.teamAplayers[i].strikerate<<endl;
        cout<<"Hundreds: "<<x.teamAplayers[i].hundreds<<endl;
        cout<<"BOWLING INFORMATION"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"Wickets : "<<x.teamAplayers[i].wickets<<endl;
        cout<<"Bowling Average : "<<x.teamAplayers[i].bowlingaverage<<endl<<endl;;
    }
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"TEAM B"<<endl;
    for(int i=0;i<11;i++){
        cout<<"Name :"<<x.teamBplayers[i].Name<<endl;
        cout<<"Age  :"<<x.teamBplayers[i].age<<endl;
        cout<<"Innings:"<<x.teamBplayers[i].innings<<endl;
        cout<<"*************************************"<<endl;
        cout<<"BATTING INFORMATION"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"Runs : "<<x.teamBplayers[i].runs<<endl;
        cout<<"High Score: "<<x.teamBplayers[i].highscore<<endl;
        cout<<"Average: "<<x.teamBplayers[i].battingaverage<<endl;
        cout<<"Strike Rate: "<<x.teamBplayers[i].strikerate<<endl;
        cout<<"Hundreds: "<<x.teamBplayers[i].hundreds<<endl;
        cout<<"BOWLING INFORMATION"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"Wickets : "<<x.teamBplayers[i].wickets<<endl;
        cout<<"Bowling Average : "<<x.teamBplayers[i].bowlingaverage<<endl<<endl<<endl;
    }
    return 0;
}
