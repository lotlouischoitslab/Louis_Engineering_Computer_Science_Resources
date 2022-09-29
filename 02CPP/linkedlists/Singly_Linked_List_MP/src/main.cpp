#include <singularlylinkedlist.hpp>
#include <stringnode.hpp>

using namespace std;

int main() {
    SLinkedList* airports = new SLinkedList();
    StringNode* lax = new StringNode;
    lax->elem = "LAX";
    airports->insert(lax->elem,0);

    StringNode* msp = new StringNode;
    msp->elem = "MSP";
    airports->insert(msp->elem,1);

    StringNode* atl = new StringNode;
    atl->elem = "ATL";
    airports->insert(atl->elem,1);

    //cout << *airports;

    airports->remove(0);

    cout << *airports;

    return 0;
}