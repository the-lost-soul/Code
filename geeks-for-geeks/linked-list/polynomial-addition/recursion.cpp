void addPolynomial(Node *p1, Node *p2)
{
    Node* data1 = p1 ;
    Node* data2 = p2 ;
    if(data1 and data2)
    {
        if(data1->pow == data2->pow)
        {
            int newCoeff = data1->coeff + data2->coeff ;
            cout << newCoeff << "x^" << data1->pow ;
            if(data1->next || data2->next)cout << " + " ;
            addPolynomial(data1->next , data2->next) ;
        }
        else if(data1->pow > data2->pow)
        {
            int coeff1 = data1->coeff ;
            cout << coeff1 <<"x^" << data1->pow << " + " ;
            addPolynomial(data1->next , data2) ;
        }
        else
        {
            int coeff2 = data2->coeff ;
            cout << coeff2 <<"x^" << data2->pow << " + " ;
            addPolynomial(data1 , data2->next) ;
        }
    }
    while(data1 and !data2)
    {
        cout << data1->coeff << "x^" << data1->pow ;
        data1 = data1->next ;
        if(data1)cout << " + " ;
    }
    
    while(!data1 and data2)
    {
        cout << data2->coeff << "x^" << data2->pow ;
        data2 = data2->next ;
        if(data2)cout << " +" ;
    }
    
}
