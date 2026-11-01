#include<iostream>
#include<pcap.h>
#include<vector>
using namespace std;


void packet_handler(u_char *user_args, const struct pcap_pkthdr *header, const u_char *packet){

cout << "\n Packet captured. Length: "<< header->len;
}


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

cout << "Found interfaces: " << endl;
for (pcap_if_t *i = alldevs; i != nullptr; i = i->next) { //all devs = # of interfaces from linked list.
     cout << i->name << endl;
     interfaces.push_back(i);
}



cout << "What interface would you like to choose, ";
cout << "enter number from #0 (first interface) to #? (last interface) going up by 1's: ";
cin >> x;

cout << "\nYou picked interface: " << interfaces[x]->name;

pcap_t *handle = pcap_open_live(interfaces[x]->name, 65535, 1, 10000, errorbuffer); // (interface, byte limit, promiscious mode, time out ms, err buf) - paramaters.

if (handle == nullptr){
    cout << "could not open network interface " << interfaces[x]->name << errorbuffer;
}


pcap_loop(handle, 5, packet_handler, nullptr);


}

return 0;


}





