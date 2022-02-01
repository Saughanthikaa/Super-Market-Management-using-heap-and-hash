#include <iostream>
#include <string>
#include<cstring>
#include<fstream>
#include<conio.h>
#include <iomanip>
#include <cctype>
#include <windows.h>
using namespace std;

int s=0;
struct product
{
    char pro_name[60];
    char serial_no[10];
    float price;
    int stock;
    product()
    {
        strcpy(pro_name," ");
        strcpy(serial_no," ");
        price=0;
        stock=0;
    }
    void get_data(struct product *r)
    {
       cout<<"\t\t\t\tPRODUCT ID :";
       cin>>serial_no;
       for(int i=0;i<s;i++)
       {
           if(strcmp(serial_no,r[i].serial_no)==0)
           {
               cout<<"\t\t\t\tPRODUCT ALREADY EXITS PPLEASE RE-ENTER\n";
               cout<<"\t\t\t\tPRODUCT ID :";
               cin>>serial_no;
           }
       }
       cout<<"\t\t\t\tPRODUCT NAME: ";
       cin>>pro_name;
       for(int i=0;i<s;i++)
       {
           if(strcmp(pro_name,r[i].pro_name)==0)
           {
               cout<<"\t\t\t\tID ALREADY EXITS PPLEASE RE-ENTER\n";
               cout<<"\t\t\t\tPRODUCT ID :";
               cin>>pro_name;
           }
       }
       cout<<"\t\t\t\tPRODUCT PRICE :";
       cin>>price;
       while(1)
       {
            if(price<=0)
         {
                cout<<"\t\t\t\tNOT VALID!PLEASE RE-ENTER\n";
                cout<<"\t\t\t\tPRODUCT PRICE :";
                cin>>price;
           }
           else
            break;
       }
       cout<<"\t\t\t\tSTOCK :";
       cin>>stock;
    }

    bool operator > ( const product& r)   // operator overloading
    {
        for(int i=0; pro_name[i]!='\0' && r.pro_name[i]!='\0'; i++)
        {
            if(pro_name[i] < r.pro_name[i])
                return false;
            else if(pro_name[i]>r.pro_name[i])
                return true;
        }
        if(strlen(this->pro_name) > strlen(r.pro_name))
            return true;
        else
            return false;
    }
    bool operator < ( const product& r)   //overloading
    {
        for(int i=0; pro_name[i]!='\0' && r.pro_name[i]!='\0'; i++)
        {
            if(pro_name[i] < r.pro_name[i])
                return true;
            else if(pro_name[i]>r.pro_name[i])
                return false;
        }
        if(strlen(this->pro_name) < strlen(r.pro_name))
            return true;
        else
            return false;
    }

    void operator=(const product& r)
    {
        strcpy(this->serial_no,r.serial_no);
        strcpy(this->pro_name,r.pro_name);
        this->price=r.price;
        this->stock=r.stock;
    }

     void display()
    {
       cout<<"\t\t\t\tPRODUCT ID :" << serial_no<<endl;
       cout<<"\t\t\t\tPRODUCT NAME:"<<pro_name<<endl;
       cout<<"\t\t\t\tPRODUCT PRICE :"<<price<<endl;
       cout<<"\t\t\t\tSTOCK :"<<stock<<endl;
       if(stock <= 0)
        cout<<"\n\t\t\t\t[NOTE:] OUT OF STOCK \n\n ";
    }

    void buy(int stock)
    {
        this->stock -= stock;
    }


};
struct product p[100];
struct product cart[100];

int soc=0;

// Used for index in heap
int x = -1;

// Predefining the heap array
product heap[1000];

// Defining formation of the heap
void heapForm(product k)
{
    x++;

    heap[x] = k;

    int child = x;

    product tmp;

    int index = x / 2;

    // Iterative heapiFy
    while (index >= 0) {

        // Just swapping if the element
        // is smaller than already
        // stored element
        if (heap[index] > heap[child]) {

            // Swapping the current index
            // with its child
            tmp = heap[index];
            heap[index] = heap[child];
            heap[child] = tmp;
            child = index;

            // Moving upward in the
            // heap
            index = index / 2;
        }
        else {
            break;
        }
    }
}

// Defining heap sort
void heapSort()
{
    int left1, right1;
    cout<<"\n";
    cout <<endl <<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;
    cout  << "| " << setw(5) << left <<"PDT ID" << "| " << setw(30) << left << "NAME"<< "| " << setw(20) << left << "PRICE" << "| " << setw(20) << left << "QTY" << "|"  <<endl<<  std::setfill( '-' )<< std::setw( 85 ) << "-" ;
        cout << std::setfill(' ');
    while (x >= 0) {
        product k;
        k = heap[0];

        // Taking output of
        // the minimum element
        if(!(strlen(k.serial_no)==1))
            cout  <<endl << "| " << setw(5) << left << k.serial_no << "| " << setw(30) << left << k.pro_name
        << "| " << setw(20) << left << k.price << "| " << setw(20) << left << k.stock << " |";


        // Set first element
        // as a last one
        heap[0] = heap[x];

        // Decrement of the
        // size of the string
        x = x - 1;

        product tmp;

        int index = 0;

        int length = x;

        // Initializing the left
        // and right index
        left1 = 1;

        right1 = left1 + 1;

        while (left1 <= length) {

            // Process of heap sort
            // If root element is
            // minimum than its both
            // of the child then break
            if (!(heap[index] > heap[left1]) && !(heap[index] > heap[right1])) {
                break;
            }

            // Otherwise checking that
            // the child which one is
            // smaller, swap them with
            // parent element
            else {

                // Swapping
                if (heap[left1] < heap[right1]) {
                    tmp = heap[index];
                    heap[index] = heap[left1];
                    heap[left1] = tmp;
                    index = left1;
                }

                else {
                    tmp = heap[index];
                    heap[index] = heap[right1];
                    heap[right1] = tmp;
                    index = right1;
                }
            }

            // Changing the left index
            // and right index
            left1 = 2 * left1;
            right1 = left1 + 1;
        }
    }

        cout <<endl << std::setfill( '-' ) << std::setw( 85 )<< '-' ;
        //system("pause");
}

// Utility function
void sort(product k[], int n)
{

    // To heapiFy
    for (int i = 0; i < n; i++) {
        heapForm(k[i]);
    }
    // Calling heap sort function
    heapSort();

}
void printArray(product p[], int n)
{
    cout <<endl <<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;
    cout  << "| " << setw(5) << left <<"PDT ID" << "| " << setw(30) << left << "NAME"<< "| " << setw(20) << left << "PRICE" << "| " << setw(20) << left << "QTY" << "|"  <<endl<<  std::setfill( '-' )<< std::setw( 85 ) << "-" ;
        cout << std::setfill(' ');
        if(n == 0)
            cout << "\nNO ITEMS";
    for (int i = 0; i <= n-1; i++)
    {
        if(!(strlen(p[i].serial_no)==1))
           cout  <<endl << "| " << setw(5) << left << p[i].serial_no << "| " << setw(30) << left << p[i].pro_name
        << "| " << setw(20) << left << p[i].price << "| " << setw(20) << left << p[i].stock << " |";
    }
    cout <<endl << std::setfill( '-' ) << std::setw( 85 )<< '-' ;
    return;

}


void delete_admin(char * filename,char *ele)
{
    ofstream wf(filename, ios::out | ios::binary);
    if(!wf)
    {
      cout << "\t\t\t\tFILE DOES NOT EXIT!!CREATING NEW FILE!!.." << endl;
    }
    int y=s;
    for(int i=0;i<s;i++)
    {
        if(strcmp(p[i].serial_no,ele)==0)   //==
        {
            y--;
        }
    }
    //wf.write(reinterpret_cast<char *>(&y), sizeof(s));
    wf.write((char *) &y ,sizeof(s));
    for(int i=0;i<s;i++)
    {
        if(strcmp(p[i].serial_no,ele)==0)
        {
            continue;   //skip
        }

        wf.write((char *) &p[i], sizeof(product));
    }
    wf.close();
}



void write_file(char * filename)
{
    ofstream wf(filename, ios::out | ios::binary);
    if(!wf)
    {
      cout << "\t\t\t\tFILE DOESNOT EXIT!!CREATING NEW FILE!!.." << endl;
    }
    //wf.write(reinterpret_cast<char *>(&s), sizeof(s));
    wf.write((char *) &s,sizeof(s));
    for(int i=0;i<s;i++)
    {

        wf.write((char *) &p[i], sizeof(product));
    }
    wf.close();
}
void read_file(char * filename)
{
    ifstream wf(filename, ios::in | ios::binary);
    if(!wf)
    {
      cout << "\t\t\t\tFILE DOESNOT EXIT!!" << endl;
      return;
    }
    //wf.read(reinterpret_cast<char *>(&s), sizeof(s));

    wf.read((char *) &s,sizeof(s));
    for(int i=0;i<s;i++)
    {
        wf.read((char *) &p[i], sizeof(p[i]));
       // cout<<p[i].pro_name;

    }
    wf.close();
}

void admin_delete(product p[])
{
   //cout<<"s value ="<<s;
   char ele[10];
   cout<<"\t\t\t\tENTER PRODUCT ID TO DELETE :";
   cin>>ele;
   delete_admin("Market.dat",ele);
   read_file("Market.dat");
   cout<<"\n";
    cout <<endl <<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;
    cout  << "| " << setw(5) << left <<"PDT ID" << "| " << setw(30) << left << "NAME"<< "| " << setw(20) << left << "PRICE" << "| " << setw(20) << left << "QTY" << "|"  <<endl<<  std::setfill( '-' )<< std::setw( 85 ) << "-" ;
        cout << std::setfill(' ');
   for(int i=0;i<s;i++)
   {
       if(!(strlen(p[i].serial_no)==1))
       cout  <<endl << "| " << setw(5) << left << p[i].serial_no << "| " << setw(30) << left << p[i].pro_name
        << "| " << setw(20) << left << p[i].price << "| " << setw(20) << left << p[i].stock << " |";
   }

   cout <<endl <<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;

}
void modify(char * filename,char *ele)
{
    int st2 = 0;
    ofstream wf(filename, ios::out | ios::binary);
    if(!wf)
    {
      cout << "FILE DOESNOT EXIT!!CREATING NEW FILE!!.." << endl;
    }
    wf.write((char *) &s,sizeof(s));
    //wf.write(reinterpret_cast<char *>(&s), sizeof(s));
    for(int i=0;i<s;i++)
    {
        if(strcmp(p[i].serial_no,ele)==0)
        {
            cout<<"\t\t\t\tEnter newly added stock:";
            cin>>st2;
            p[i].stock = p[i].stock+st2;
             cout<<"\t\t\t\tSTOCK UPDATED"<<"\n";
        }

        wf.write((char *) &p[i], sizeof(product));
    }
    wf.close();
    read_file("Market.dat");

}
void admin()
{
    int ch;
    int n=0;

    read_file("Market.dat");
    //cout<<s<<endl;
    //system("pause");
    do
    {
        system("cls");
        cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;
        cout<<"                                                      XYZ SUPERMARKET MANAGING SOFTWARE\n";
        cout<<"                                                              ADMIN MENU       ";
        cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;
        cout<<"\n\t\t\t\t1.INSERT\n\t\t\t\t2.DISPLAY\n\t\t\t\t3.DELETE\n\t\t\t\t4.UPDATE STOCK\n\t\t\t\t5.EXIT\n\n\t\t\t\tENTER YOUR CHOICE: ";
        cin>>ch;
        switch(ch)
        {

            case 1 :
                n=0;
                {
                    int num;
                    cout<<"\t\t\t\tNO OF PRODUCTS :";
                    cin>>num;
                    for(;n<num;n++)
                    {
                        p[s].get_data(p);
                        s++;

                    }
                    n = sizeof(p) / sizeof(p[0]);
                    //printf("%d s value :",s);
                    printArray(p, n);
                    write_file("Market.dat");
                }
                break;
            case 2 :
                {
                    sort(p, s);
                }
            break;
            case 3 :
                {
                    admin_delete(p);     //x=s
                    //cout<<"\n s value ="<<s<<"\n";
                }
                break;
            case 4:
                {
                    char pdt[10];
                    cout<<"\t\t\t\tProduct  id: ";
                    cin>>pdt;
                    modify("Market.dat",pdt);
                }

            break;

            case 5 :
                    write_file("Market.dat");
                    return;
            break;
            default : printf("\n\nWRONG CHOICE\n\n");
        }
        cout<<"\n";
        system("pause");

    }while(ch!=4);

    return;
}

struct node
{
    product data;
    node* next;
};

class linkedList{
    node* head;
    public:

        linkedList()
        {
            head = NULL;
        }

        bool isEmpty()
        {
            if(head==NULL)
                return true;
            return false;
        }

        void insert(product d)
        {
             /* 1. allocate node */
            node* new_node = new node();

            new_node->data = d;

            new_node->next = head;
            head = new_node;
        }

        void display()
        {
            node* n=head;
            while (n != NULL)
                {
                   n->data.display();
                    n = n->next;
                }
        }

        void search(char* t)
        {
           int st;
            node* n=head;
           while (n != NULL)
                {
                    if(strcmp(n->data.pro_name,t)==0)
                    {
                         n->data.display();
                         if(n->data.stock==0)
                         {
                             return;
                         }
                         menu:
                             cout<<"\n\n\t\t\t\tQuantity:";
                             cin>>st;
                         if(st > n->data.stock)
                         {
                             cout<<"[WARNING] INSUFFICIENT GOODS\n";
                             goto menu;
                         }
                         else
                            {
                            n->data.buy(st);
                             if(st>0)
                             {

                                 cart[soc]= n->data;
                                 cart[soc].stock = st;
                                 soc++;

                                }
                            }

                            return;
                        }
                                n = n->next;

                        }
                    cout<<"\t\t\t\tNO PRODUCT FOUND";

}

         void update()
        {
            node* n=head;
            while (n != NULL)
                {
                    p[s] = n->data;
                    s++;
                    n = n->next;
                }
        }
};

class Hashmap{

    linkedList array[26];

    public:
        void insert(product d)
        {
           array[hashcode(d.pro_name)].insert(d);
        }

        void buy(char* d)
        {
           array[hashcode(d)].search(d);
           updateInP();
           write_file("Market.dat");

        }

        int hashcode(char* s)
        {
            if(s[0] > 90)
                return s[0]-97;
            else
                return s[0]-65;
        }
        void display()
        {
            for(int i =0 ;i<26;i++)
            {
                if(!array[i].isEmpty())
                {
                    array[i].display();
                }
            }
        }
        void updateInP()
        {
            s = 0;
            for(int i =0 ;i<26;i++)
            {
                if(!array[i].isEmpty())
                {
                    array[i].update();
                }
            }

        }
};

class BST
{
    struct node
    {
        product d;
        node* left;
        node* right;

        node()
        {
            left=NULL;
            right=NULL;
        }
    } ;
    node* root;
    public:
        BST()
        {
            root = NULL;
        }

        void insertRecursive(node* &root,product d)
        {
                if (!root)
            {
                root= new node;
                root->d=d;
                return ;
            }

            if (d > root->d)
            {
                insertRecursive(root->right, d);
            }
            else
            {
                insertRecursive(root->left, d);
            }


        }
        void insert(product d)
        {
                insertRecursive(root,d);
        }

        void displayRecursive(BST::node* root1)
        {

            if (root1==NULL) {
                return;
            }

            displayRecursive(root1->left);
            root1->d.display();
            displayRecursive(root1->right);
        }

        void display()
        {
            displayRecursive(root);
        }
};

void displayCart()
{
    BST b;
    for(int i=0;i<soc;i++)
    {
        b.insert(cart[i]);
    }

    b.display();
}
void bill()
{
     double total = 0;
               cout <<endl <<  std::setfill( '-' ) << std::setw( 85 ) << '-'
               << std::setfill(' ') << std::endl;
    cout  << "| " << setw(5) << left <<"SNO" << "| " << setw(30) << left << "NAME"
        << "| " << setw(20) << left << "PRICE" << "| " << setw(20) << left << "QTY" << "|"  <<endl<<  std::setfill( '-' )<< std::setw( 85 ) << "-" ;
        cout << std::setfill(' ');
        if(soc == 0)
            cout << "\nNO ITEMS";
        for(int i=0; i < soc; i++)
        {
             cout  <<endl << "| " << setw(5) << left << cart[i].serial_no << "| " << setw(30) << left << cart[i].pro_name
        << "| " << setw(20) << left << cart[i].price << "| " << setw(20) << left << cart[i].stock << "|";
        total+=cart[i].price * cart[i].stock;
        }
        cout <<endl << std::setfill( '-' ) << std::setw( 85 )
              << '-' ;
        cout << "\nTOTAL: " << total;
}



void customer()
{
    system("cls");

    char d[60];
    int ch;
    read_file("Market.dat");
    Hashmap HT;
     for(int i=0;i<s;i++)
    {
        HT.insert(p[i]);
    }
    do{
         system("cls");
         cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;
        cout<<"                                                      XYZ SUPERMARKET MANAGING SOFTWARE\n";
        cout<<"                                                              CUSTOMER MENU       ";
        cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;
        cout<<"\n\t\t\t\t1.BUY\n\t\t\t\t2.EXIT\n\n\t\t\t\tENTER YOUR CHOICE: ";
        cin>>ch;
        switch(ch)
        {

            case 1 :
                int cn;
                do{
                cout<<"\n\t\t\t\tPRODUCT NAME: ";
                cin>>d;
                HT.buy(d);
                cout<<"\n\t\t\t\tDo you want to continue shopping?\n\t\t\t\tIf Yes press '1' else '0':";
                cin>>cn;
                }while(cn==1);
                system("cls");
                cout<<"\t\t\t\t\n\nYOUR CART:\n";
                if(soc>0)
                {
                    displayCart();
                cout<<"Press any key to view bill";
                getch();
                bill();
                }
                else{
                    cout<<"[NOTE] NO PRODUCTS ";
                }
                break;
            case 2 :
                soc = 0;
               return;
                break;
            default : printf("\n\n\t\t\t\tWRONG CHOICE\n\n");
    }
        cout<<"\n";
        system("pause");

    }while(ch!=4);

    return;


}

bool login()
{
    system("cls");
    char password[32];
    string pw = "admin";

    cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 85 ) << '-'
           << std::setfill(' ') << std::endl;
cout<<"                                                      XYZ SUPERMARKET MANAGING SOFTWARE       ";
cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 85 ) << '-'
           << std::setfill(' ') << std::endl;cout<<"                                                                            "<<endl;


    cout<<"\n\t\t\t\t\tEnter password: ";
    int i = 0;
    char a;
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            password[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)

        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            password[i]='\0';//null means end of string.
            break;//break the loop
        }
    }

    if( pw == password)
    {
        return true;
    }
    else
    {
        cout<<"\n\n\t\t\t\t\tWRONG PASSWORD!! TRY AGAIN!\n";
        system("pause");
        login();
    }

}


int main()
{
    system("Color F0");
    int ch;
    if(login() == true)
    {

    do
    {
        system("cls");
        cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;
        cout<<"                                                      XYZ SUPERMARKET MANAGING SOFTWARE       ";
        cout <<endl <<"\t\t\t"<<  std::setfill( '-' ) << std::setw( 85 ) << '-'<< std::setfill(' ') << std::endl;
        cout<<"\n\t\t\t\t1.ADMIN\n\t\t\t\t2.CUSTOMER\n\t\t\t\t3.EXIT\n\n\t\t\t\tENTER YOUR CHOICE :";
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : admin();
                    break;
            case 2 : customer();
                    break;
            case 3 : exit(0);
                    break;
            default : cout<<"\t\t\t\tCHOOSE A CORRECT OPTION!!\n\n\n";
        }
    }while(ch!=3);
    }
    else{
        cout<<"\t\t\t\t[WARNING] WRONG PASSWORD!!\nTry again...";
        login();
    }
}
