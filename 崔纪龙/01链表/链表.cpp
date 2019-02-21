#include<iostream>
using namespace std;

class A
{
public:
    string name;
    string age;
    A *next=NULL;
};
void push(A *H,string m,string y)
{
    A *p=H;
    A *s=new A;
    while (p->next)
    {
        p=p->next;
    }
    p->next=s;
    s->next = NULL;
    s->name=m;
    s->age=y;
    cout<<"put ok!"<<endl;
}
void addd(A *H,int t,string m,string y)
{
    A *p=H;
    int i=0;
    A *s=new A;
    while (p)
    {
        if(i==t-1-1)
            break;
        p=p->next;
        i++;
    }
    s->next = p->next;
    p->next=s;
    s->name=m;
    s->age=y;
    cout<<"add ok!"<<endl;
}
void chazhao(A *H,string t)
{
    A *p=H;
    while (p)
    {
        if(p->name==t)
        {
            break;
        }
        p=p->next;
    }
    cout<<p->name<<"   "<<p->age<<"   "<<endl;
}
void popp(A *H)
{
    H->name=H->next->name;
    H->age=H->next->age;
    H->next=H->next->next;

}
void poppp(A *H)
{
    A *p=H;
    while(p->next->next)
    {
        p=p->next;
    }
    p->next=NULL;
}

void shanchu(A *H,string t)
{
    A *p=H;
    A *s=new A;
    int i=0;
    while (p!=NULL)
    {
        if(p->name==t)
        {
            break;
        }
        p=p->next;
        i++;
    }
    if((p->name==t)&&(i!=0)&&(p->next!=NULL))
    {
        p->name=p->next->name;
        p->age=p->next->age;
        p->next=p->next->next;
        cout<<"ok"<<endl;
    }
    else if((p->name==t)&&(i==0))
    {
        popp(H);
        cout<<"ok"<<endl;
    }
    else if((p->name==t)&&(p->next==NULL)&&(i!=0))
    {
        poppp(H);
        cout<<"ok"<<endl;
    }
    else if((p->name!=t))
    {
        cout<<"there is no such information"<<endl;
    }
}
void show(A *H,int q)
{
    A *p=H;
    int i=0;
    while(p)
    {
        if(q-1==i)
        {
            cout<<p->name<<"   "<<p->age<<"   ";
            break;
        }
        p=p->next;
        i++;
    }
}
void xiugai(A *H,string t,int p_,string k)
{
    A *p=H;
    A *s=new A;
    int i=0;
    while (p)
    {
        if(p->name==t)
        {
            break;
        }
        p=p->next;
        i++;
    }
    if(p_==1)
    {
        p->name=k;
        cout<<"name ok!"<<endl;
    }
    if(p_==2)
    {
        p->age=k;
        cout<<"age ok!"<<endl;
    }
}
void showw(A *H)
{
    A *p=H;
    int i=1;
    while(p)
    {
        cout<<p->name<<"   "<<"   "<<p->age<<"   "<<endl;
        p=p->next;
        i++;
    }
}

int main()
{
    int c;
    A *H=new A;
    int n,i,v;
    int j=1;
    string w,y;
    cout<<"************************************\n";
    cout<<"*输入1创建一个头(或在末尾添加)******\n";
    cout<<"**********************输入2插入一个*\n";
    cout<<"*输入3查找一个信息******************\n";
    cout<<"**********************输入4删除一个*\n";
    cout<<"*输入5查你想看的********************\n";
    cout<<"**********************输入6修改信息*\n";
    cout<<"***输入其他展示整个*****************\n";
    cout<<"************************************\n"<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"(注：至少有一个头才可以使用2~5功能)\n";//查找修改等功能不支持找不存在的QAQ
    while(1)
    {
        c=0;
        cout<<"ok:     ";
        cin>>c;
        if(c==1)
        {
            if(j==1)
            {
                cout<<"put 1 name:  ";
                cin>>w;
                H->name=w;
                cout<<"put 1 age:  ";
                cin>>y;
                H->age=y;
                H->next= NULL;
                j++;
            }
            else
            {
                w=y='0';
                cout<<"put"<<j<<"name:  ";
                cin>>w;
                cout<<"put"<<j<<"age:  ";
                cin>>y;
                push(H,w,y);
                j++;
            }
        }
        else if(c==2)
        {
            cout<<"where do you want to add it?:  ";
            int t=0;
            cin>>t;
            w=y='0';
            cout<<"put he name:  ";
            cin>>w;
            cout<<"put he age:  ";
            cin>>y;
            addd(H,t,w,y);
            j++;
        }
        else if(c==3)
        {
            cout<<"put you want get name:";
            string t;
            cin>>t;
            cout<<"he information is:"<<endl;
            chazhao(H,t);
        }

        else if(c==4)
        {
            cout<<"want delete name:";
            string l;
            cin>>l;
            shanchu(H,l);
        }
        else if(c==5)
        {
            cout<<"you want the number of information:";
            int g;
            cin>>g;
            show(H,g);
        }
        else if(c==6)
        {
            cout<<"information`name that you want to change";
            string u,k;
            int p_;
            cin>>u;
            cout<<"cahng name put 1"<<endl<<"cahng age put 2"<<endl;
            cin>>p_;
            if(p_==1)
            {
                cout<<"put want name"<<endl;
                cin>>k;
                xiugai(H,u,p_,k);
            }
            if(p_==2)
            {
                cout<<"put want age"<<endl;
                cin>>k;
                xiugai(H,u,p_,k);
            }
            cout<<"ok";
        }
        else
        {
            showw(H);
        }
    }
    return 0;
}

