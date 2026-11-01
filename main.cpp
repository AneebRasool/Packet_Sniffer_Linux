#include<iostream>
#include<pcap.h>
#include<vector>
using namespace std;

int main()
{

pcap_if_t *alldevs = nullptr;
char errorbuffer[PCAP_ERRBUF_SIZE];
int interfacesuccess = pcap_findalldevs(&alldevs, errorbuffer); //find default interface to capture (ex eth0)


if (interfacesuccess == -1){

    cout << "error found: " << errorbuffer;
}


else{


int x;
vector<pcap_if_t*> interfaces;

cout << "Found interfaces: ";
for (pcap_if_t *i = alldevs; i != nullptr; i = i->next) { //all devs = # of interfaces from linked list.
     cout << i->name << endl;
     interfaces.push_back(i);
}




cout << "What interface would you like to choose: ";
cout << "Enter Number from #0 (first interface) to #? (last interface) going up by 1's": << endl;
cin >> x;

cout << "You picked interface: " << interfaces[x]->name;

pcap_t *handle = pcap_open_live(interfaces[x]->name, 65535, 1, 1000, errorbuffer); // (interface, byte limit, promiscious mode, time out ms, err buf) - paramaters.

if (handle == nullptr){
    cout << "could not open network interface " << interfaces[x]->name << errorbuffer;
}

}



return 0;


}