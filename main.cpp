#include <iostream>

using namespace std;
typedef string Dato;

class DoubleNode{
protected:
    Dato dato;
    DoubleNode* forward;
    DoubleNode* backward;

public:
    DoubleNode(Dato t)
    {
        this->dato = t;
        this->forward = this->backward = NULL;
    }

    Dato Nodedato() const{return dato;}

    DoubleNode* forwardNode() {
        //cout << this->dato << " pointing to next: " << this->forward << endl;
        return this->forward;
    }
    DoubleNode* backwardNode() {
        //cout << this->dato << " pointing to previous: " << this->backward << endl;
        return this->backward;
    }

    void putforward(DoubleNode* a){
        this->forward = a;
    } //set forward pointer
    void putbackward(DoubleNode* a){
        this->backward = a;
    } //set backward pointer

friend class List;
};

class List
{
protected:
    DoubleNode* first;
public:
    List()
    {
        first = NULL;
    }
    void createList();
    void insertHead(Dato entry);
    void visualize();
    void visualize_reverse();
    void INSERT(string source, string destination, string new_data, int method);
    void DELETE(Dato name);
    DoubleNode *get_first();
    DoubleNode *find_node(string node_name);
};

bool can_second(DoubleNode *source,DoubleNode *destination);
bool inverse(DoubleNode* source, DoubleNode* destination);
bool is_double(DoubleNode* source, DoubleNode* destination);
string reverse_destination_source(DoubleNode *source, DoubleNode *destination);


DoubleNode* List::get_first(){
    return this->first;
}

DoubleNode* List::find_node(string node_name){
    DoubleNode *aux;
    DoubleNode *last_node;

    aux = this->first; //auxiliary pointer is the first pointer of the list

    while(aux!=NULL){ //while the aux pointer has not arrived to the end
        //cout << "searching " << aux->Nodedato() << endl;
        if (aux->Nodedato()==node_name) return aux;
        last_node = aux;
        aux = aux->forwardNode();
    }

    while(last_node!=this->first){ //the pointer comes back to the first position
        //cout << "searching " << last_node->Nodedato() << endl;
        if (last_node->Nodedato()==node_name) return last_node;
        last_node = last_node->backwardNode();

    }
    //return NULL;
}

void List::createList()
{
    //DoubleNode *head = NULL;

    DoubleNode *NTHU = new DoubleNode("NTHU");     // create NTHU
    this->first = NTHU;         // first = NULL = "head"

    DoubleNode *TSMC = new DoubleNode("TSMC");     // create TSMC

    //first->putforward(NTHU); //first ----> NTHU
    NTHU->putforward(TSMC);  //first ----> NTHU ----> TSMC
    TSMC->putbackward(NTHU); //first ----> NTHU <===> TSMC
    TSMC->putforward(NULL);  //first ----> NTHU <===> TSMC ----> NULL
    //cout << TSMC->forward;
    //cout << can_second(NTHU,TSMC);
}

/*
void List::insertHead(Dato entry)
{
    DoubleNode* nuevo;
    nuevo = new DoubleNode (entry);
    nuevo->putforward(cabeza);
    if (cabeza != NULL )
    cabeza -> ponerAtras(nuevo);
    cabeza = nuevo;
}*/

void List::visualize()
{
 DoubleNode* n; //initialize aux node
 DoubleNode* last_node;

 n = this->first; //aux node is the first node
 cout << n->Nodedato();
 n = n->forwardNode();


 while (n != NULL)
 {
 cout << "->" << n->Nodedato();// << c;
 last_node = n;
 n = n->forwardNode();
 }
//cout << endl;
 while (last_node != this->first)
 {
     last_node = last_node->backwardNode();
     cout << "->" << last_node->Nodedato();
 }
}




void List::INSERT(string source_name, string destination_name, string new_data, int method)
{
    DoubleNode *source = find_node(source_name);
    DoubleNode *destination = find_node(destination_name); //source->forwardNode();
    //cout << destination_name << endl;
    //cout << reverse_destination_source(source,destination) << endl;

    if(source==NULL){
        //cout << "source doesnt exist" << endl;
    }
    else if(destination==NULL){
        //cout << "destination doesnt exist" << endl;
    }

    else if(method==1 and !inverse(source,destination)){ // source <===> destination
        //cout << "entra 1";
        DoubleNode *new_node = new DoubleNode(new_data);
        new_node->putforward(destination);
        source->putforward(new_node);
    }
    else if(method==1 and inverse(source,destination)){ // destination <===> source
        //cout << "entra 2";
        DoubleNode *new_node = new DoubleNode(new_data);
        new_node->putbackward(destination);
        source->putbackward(new_node);
    }
    else if(method==2 and is_double(source,destination) and !inverse(source,destination)){ //source <===> destination
        //cout << "entra 3";
        DoubleNode *new_node = new DoubleNode(new_data);
        new_node->putforward(destination);
        source->putforward(new_node);
        new_node->putbackward(source);
        destination->putbackward(new_node);
    }
    else if(method==2 and is_double(source,destination) and inverse(source,destination)){ //destination <===> source
        //IN CASE OF ERROR IS THIS FUCKING SHIT
        //cout << "entra 4";
        DoubleNode *new_node = new DoubleNode(new_data);
        new_node->putforward(source);
        destination->putforward(new_node);
        new_node->putbackward(destination);
        source->putbackward(new_node);
    }
    else if(method==2 and !is_double(source,destination) and !inverse(source,destination)){ //source ---> destination
        //cout << "entra 5";
        DoubleNode *new_node = new DoubleNode(new_data);
        new_node->putforward(destination);
        source->putforward(new_node);
    }
    else if(method==2 and !is_double(source,destination) and inverse(source,destination)){ //destination ---> source
        //cout << "entra 6";
        DoubleNode *new_node = new DoubleNode(new_data);
        new_node->putbackward(destination);
        source->putbackward(new_node);
    }

    else cout << "sth is going on" << endl;

}

void List::DELETE (string entrada){
    DoubleNode* node_todelete = find_node(entrada);
    //cout << "found: " << node_todelete->Nodedato() << endl;


    DoubleNode* search_forward = this->first;
    DoubleNode* last_f = this->first;
    DoubleNode* last_b;


    DoubleNode* forward_ = node_todelete->forwardNode(); //D
    DoubleNode* backward_ = node_todelete->backwardNode(); //F

    bool B_exist = 0;
    while(search_forward->forwardNode()!=NULL){ //while for finding node B (B to D)
        //cout << (search_forward->forwardNode()->Nodedato()) << endl;
        if (search_forward->forwardNode()!=NULL and search_forward->forwardNode()->Nodedato()==entrada){ B_exist=1; break;}
        search_forward = search_forward->forwardNode();
    }
    if (B_exist==0){search_forward=NULL;}

    while(last_f!=NULL){ //while til the end
        last_b = last_f;
        last_f = last_f->forwardNode();
    }

    bool E_exist = 0;
    DoubleNode* search_backward = last_b;//last_f->backwardNode();

    while(search_backward!=this->first){ //while for finding node E (E to F)
        if (search_backward->backward->Nodedato()==entrada){ E_exist=1; break;}
        search_backward = search_backward->backwardNode();
    }
    if(E_exist==0){search_backward=NULL;}
    //mapping:
    // B to D
    // search_forward  to forward_
    // E to F
    // search_backward to backward_
    //cout << endl << "B: " << search_forward->Nodedato() << endl;
    //cout << "D: " << forward_ << endl;
    //cout << "E: " << search_backward->Nodedato() << endl;
    //cout << "F: " << backward_->Nodedato() << endl;

    bool flag = 0;
    if(B_exist and search_forward!=NULL and forward_!=NULL){
        //cout << "case 1" << endl;
        search_forward->putforward(forward_);
        flag = 1;
    }
    if(E_exist and search_backward!=NULL and backward_!=NULL){
        //cout << "case 2" << endl;
        search_backward->putbackward(backward_);
        flag = 1;
    }
    else if(search_forward->Nodedato()!= last_b->backwardNode()->Nodedato() and flag==0){
        //cout << "case 3" << endl;
        search_forward->putforward(last_b->backwardNode());
        search_forward->forwardNode()->putforward(NULL);
    }
    else if(search_forward->forwardNode()==last_b and last_b->backwardNode()==search_forward and flag==0){
        //cout << "case 4" << endl;
        search_forward->putforward(NULL);
    }
}


bool inverse(DoubleNode* source, DoubleNode* destination){
    if (destination->forwardNode()==source or source->backwardNode()==destination) return true;
    else return false;
}
bool is_double(DoubleNode* source, DoubleNode* destination){
    if ((source->forwardNode()==destination and destination->backwardNode()==source) or
        (destination->forwardNode()==source and source->backwardNode()==destination)) return true;
    else return false;
}

string reverse_destination_source(DoubleNode *source, DoubleNode *destination){
    if (source->forwardNode()==destination) return "simpleregular";

    else if ((source->forwardNode()==destination and destination->backwardNode()==source) or
             (destination->forwardNode()==source and source->backwardNode()==destination)) return "doubleregular";

    else if (destination->forwardNode()==source or source->backwardNode()==destination) return "directinverse";

    //else if (destination->forwardNode()==source and source->backwardNode()==destination) return "doubleregular";

    else return "none";
}

bool can_second(DoubleNode *source,DoubleNode *destination){
    if (source->forwardNode() == destination and destination->backwardNode() == source and // source <===> destination
        (reverse_destination_source(source,destination)=="simpleregular" or
         reverse_destination_source(source,destination)=="doubleregular")) return true;
    if (destination->forwardNode() == source and source->backwardNode() == destination and // destination <===> source
        (reverse_destination_source(source,destination)=="directinverse" or
         reverse_destination_source(source,destination)=="directinverse")) return true;
    //else if (destination->forwardNode()==source and source->backwardNode()==destination) return true;
    else return false;
}

int main()
{
    /*
    10
    INSERT NTHU TSMC APPLE 2
    INSERT APPLE NTHU Mackay 1
    INSERT APPLE Mackay KFSH 1
    INSERT Mackay NTHU ITRI 2
    DELETE ITRI
    INSERT TSMC APPLE ITRI 2
    DELETE APPLE
    INSERT ITRI TSMC HCHS 1
    INSERT TSMC ITRI MTK 2
    DELETE TSMC

    NTHU->ITRI->HCHS->MTK->ITRI->KFSH->Mackay->NTHU
    */

    List Lista = List(); //initialize list and create it
    Lista.createList();


    int commands;
    cin >> commands;

    string entrada[commands];

    int reverse_count = 2;

    for (int i=0; i<commands; i++){
        cin >> entrada[i];
        if (entrada[i]=="INSERT" and reverse_count%2==0){
            string source;
            string destination;
            string newnode;
            cin >> source;
            cin >> destination;
            cin >> newnode;
            int method;
            cin >> method;
            if (newnode==source or newnode==destination){}
            else Lista.INSERT(source,destination,newnode,method);
        }
        if (entrada[i]=="INSERT" and reverse_count%2!=0){
            string source;
            string destination;
            string newnode;
            cin >> destination;
            cin >> source;
            cin >> newnode;
            int method;
            cin >> method;
            if (newnode==source or newnode==destination){}
            else Lista.INSERT(source,destination,newnode,method);
        }
        if (entrada[i]=="DELETE"){
            string delete_name;
            cin >> delete_name;
            Lista.DELETE(delete_name);
        }
        if (entrada[i]=="REVERSE"){
            reverse_count++;
        }
    }

    Lista.visualize();
    cout << endl;

    return 0;
}
