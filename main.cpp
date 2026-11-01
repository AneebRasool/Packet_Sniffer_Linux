#include<iostream>
#include<pcap.h>
using namespace std;

int main()
{

pcap_if_t *alldevs = nullptr;
char errorbuffer[PCAP_ERRBUF_SIZE];
int interfacesuccess = pcap_findalldevs(&alldevs, errorbuffer); //find default interface to capture (ex eth0)


if (interfacesuccess == -1){

    cout << "error found: " << errorbuffer;
}


for (pcap_if_t *i = alldevs; i != nullptr; i = i->next) { //all devs = # of interfaces.
    cout << "Found aen interface: " << i->name << endl;
}


return 0;


}