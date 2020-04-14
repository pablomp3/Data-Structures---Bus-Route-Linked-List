#include <iostream>

using namespace std;

typedef string Dato;

class DoubleNode{
protected:
    Dato dato;
    DoubleNode* forward;
    DoubleNode* backward;
public:
    DoubleNode(Dato t){
        this->dato = t;
        this->forward=this->backward=NULL;
        }
    Dato Nodedato() const{return dato;}
    DoubleNode*forwardNode(){
        return this->forward;}
    DoubleNode*backwardNode(){
        return this->backward;}

    void putforward(DoubleNode*a){
        this->forward=a;}
    void putbackward(DoubleNode*a){
        this->backward=a;}
    void putname(string name){
        this->dato=name;}

    friend class List;
};

class List{
protected:
    DoubleNode*first;
public:
    List(){
        first = NULL;}

    void createList();
    void visualize();
    void INSERT(string source, string destination, string new_data, int method);
    void DELETE(Dato name);
    void RENAME(string old_name, string new_name);
    int TOTAL();
    int DISTANCE(string source_name, string destination_name);
    DoubleNode*get_first();
    DoubleNode*find_node(string node_name);
};

bool inverse(DoubleNode*source, DoubleNode*destination);
bool is_double(DoubleNode*source, DoubleNode*destination);

DoubleNode*List::get_first(){
    return this->first;
    }

DoubleNode*List::find_node(string node_name){
    DoubleNode*aux;
    DoubleNode*last_node;
    DoubleNode*non_existent = new DoubleNode("NO");

    aux=this->first;

    while(aux!=NULL){
        if(aux->Nodedato()==node_name) return aux;
        last_node = aux;
        aux = aux->forwardNode();
    }
    while(last_node!=this->first){
        if(last_node->Nodedato()==node_name) return last_node;
        last_node = last_node->backwardNode();
    }
    return non_existent;
}

void List::createList(){
    DoubleNode*NTHU = new DoubleNode("NTHU");
    this->first=NTHU;
    DoubleNode*TSMC = new DoubleNode("TSMC");

    NTHU->putforward(TSMC);
    TSMC->putbackward(NTHU);
    TSMC->putforward(NULL);
}

void List::visualize(){
    DoubleNode*n;
    DoubleNode*last_node;
    n = this->first;
    cout << n->Nodedato();
    n = n->forwardNode();

    while(n!=NULL){
        cout << "->" << n->Nodedato();
        last_node=n;
        n=n->forwardNode();
    }
    cout << endl;
    while(last_node!=this->first){
        last_node = last_node->backwardNode();
        cout << "->" << last_node->Nodedato();
    }
}

int List::TOTAL(){
    DoubleNode*n;
    DoubleNode*last_node;
    int counter = 0;
    n = this->first;
    //cout << n->Nodedato();
    n = n->forwardNode();

    while(n!=NULL){
        //cout << "->" << n->Nodedato();
        last_node=n;
        n=n->forwardNode();
        counter++;
    }

    while(last_node!=this->first){
        last_node = last_node->backwardNode();
        //cout << "->" << last_node->Nodedato();
        counter++;
    }
    return counter;
}

void List::RENAME(string old_name, string new_name){
    DoubleNode*old_node = find_node(old_name);
    old_node->putname(new_name);
}

int List::DISTANCE(string source_name, string destination_name){
    DoubleNode*source = find_node(source_name);
    DoubleNode*source_orig = source;
    DoubleNode*destination = find_node(destination_name);
    DoubleNode*last;

    bool flag = 0;
    int counter = 0;

    if (source->Nodedato()=="NO" and destination->Nodedato()=="NO"){
            //cout << "Missing both" << endl;
            flag = 1;
            return 122;
    }
    if (source->Nodedato()=="NO" and flag==0){
            //cout << "Missing src" << endl;
            return 123;
    }
    if (destination->Nodedato()=="NO" and flag==0){
            //cout << "Missing dst" << endl;
            return 124;
    }

    while(source!=NULL){
        if(source==destination) return counter;
        last = source;
        source = source->forwardNode();
        counter++;
    }
    counter--;
    while(last!=NULL){
        if(last==destination) return counter;
        if(last==source_orig) counter=0;
        last = last->backwardNode();
        //cout << "->" << last_node->Nodedato();
        counter++;
    }
    return counter;
}

void List::INSERT(string source_name, string destination_name, string new_data, int method){
    DoubleNode*source = find_node(source_name);
    DoubleNode*destination = find_node(destination_name);

    if(source==NULL){

    }
    else if(destination==NULL){

    }
    else if(method==1 and !inverse(source,destination)){
        //cout << "entra 1" << endl:
        DoubleNode*new_node = new DoubleNode(new_data);
        new_node->putforward(destination);
        source->putforward(new_node);
    }
    else if(method==1 and inverse(source,destination)){
        //cout << "entra 2" << endl:
        DoubleNode*new_node = new DoubleNode(new_data);
        new_node->putbackward(destination);
        source->putbackward(new_node);
    }
    else if(method==2 and is_double(source,destination) and !inverse(source,destination)){
        //cout << "entra 3" << endl:
        DoubleNode*new_node = new DoubleNode(new_data);
        new_node->putforward(destination);
        source->putforward(new_node);
        new_node->putbackward(source);
        destination->putbackward(new_node);
    }
    else if(method==2 and is_double(source,destination) and inverse(source,destination)){
        //cout << "entra 4" << endl:
        DoubleNode*new_node = new DoubleNode(new_data);
        new_node->putforward(source);
        destination->putforward(new_node);
        new_node->putbackward(destination);
        source->putbackward(new_node);
    }
    else if(method==2 and !is_double(source,destination) and !inverse(source,destination)){
        //cout << "entra 5" << endl:
        DoubleNode*new_node = new DoubleNode(new_data);
        new_node->putforward(destination);
        source->putforward(new_node);
    }
    else if(method==2 and !is_double(source,destination) and inverse(source,destination)){
        //cout << "entra 6" << endl:
        DoubleNode*new_node = new DoubleNode(new_data);
        new_node->putbackward(destination);
        source->putbackward(new_node);
    }
    else{
        cout << "sth is going on" << endl;
        cout << inverse(source,destination) << endl;
        cout << is_double(source,destination) << endl;
    }

}

bool inverse(DoubleNode*source, DoubleNode*destination){
    if(destination->forwardNode()==source or source->backwardNode()==destination) return true;
    else return false;
}
bool is_double(DoubleNode*source,DoubleNode*destination){
    if ((source->forwardNode()==destination and destination->backwardNode()==source) or (destination->forwardNode()==source and source->backwardNode()==destination)) return true;
    else return false;
}

int main()
{
    /*List Lista = List();
    Lista.createList();
    Lista.INSERT("NTHU","TSMC","APPLE",1);
    Lista.INSERT("TSMC","NTHU","NODO",1);
    Lista.RENAME("TSMC","CACA");
    cout << "distance" << Lista.DISTANCE("NTHU","TSMC") << endl;

    cout << "Total " << Lista.TOTAL() << endl;
    Lista.visualize();
    cout << endl;
    return 0;*/


    List Lista = List();
    Lista.createList();
    int commands;
    cin >> commands;

    string entrada[commands];

    for(int i=0; i<commands; i++){
        cin >> entrada[i];
        if (entrada[i]=="INSERT"){
            //cout << "inserta " << entrada[i] << endl;
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
        if (entrada[i]=="RENAME"){
            //cout << "cambia nombre " << entrada[i] << endl;
            string oldname;
            string newname;
            cin >> oldname;
            cin >> newname;
            Lista.RENAME(oldname,newname);
        }
    }

    int instr;
    cin >> instr;

    int value[instr];
    string initia[instr];
    string finale[instr];

    for (int i=0; i<instr; i++){

        string init;
        string ende;
        cin >> init;
        cin >> ende;
        if (Lista.DISTANCE(init,ende)==122){
            value[i] = 122;
            initia[i] = init;
            finale[i] = ende;
            //cout << init << " " << ende << " " << "Missing both";
        }
        else if (Lista.DISTANCE(init,ende)==123){
            value[i] = 123;
            initia[i] = init;
            finale[i] = ende;
            //cout << init << " " << ende << " " << "Missing src" << endl;
        }
        else if (Lista.DISTANCE(init,ende)==124){
            value[i] = 124;
            initia[i] = init;
            finale[i] = ende;
            //cout << init << " " << ende << " " << "Missing dst" << endl;
        }
        else{
            value[i] = Lista.DISTANCE(init,ende);
            initia[i] = init;
            finale[i] = ende;
            //cout << init << " " << ende << " " << Lista.DISTANCE(init,ende) << endl;
        }
    }

    cout << "Total " << Lista.TOTAL() << endl;
    for (int i=0; i<instr; i++){
        if (value[i]==122){
            cout << initia[i] << " " << finale[i] << " Missing both" << endl;
        }
        else if (value[i]==123){
            cout << initia[i] << " " << finale[i] << " Missing src" << endl;
        }
        else if (value[i]==124){
            cout << initia[i] << " " << finale[i] << " Missing dst" << endl;
        }
        else cout << initia[i] << " " << finale[i] << " " << value[i] << endl;
    }
    //cout << endl;
    //Lista.visualize();
    return 0;

}
