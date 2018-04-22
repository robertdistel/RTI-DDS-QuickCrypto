/* test_subscriber.cxx

A subscription example

This file is derived from code automatically generated by the rtiddsgen 
command:

rtiddsgen -language C++11 -example <arch> test.idl

Example subscription of type MyType automatically generated by 
'rtiddsgen'. To test them, follow these steps:

(1) Compile this file and the example publication.

(2) Start the subscription on the same domain used for RTI Data Distribution
Service  with the command
objs/<arch>/test_subscriber <domain_id> <sample_count>

(3) Start the publication on the same domain used for RTI Data Distribution
Service with the command
objs/<arch>/test_publisher <domain_id> <sample_count>

(4) [Optional] Specify the list of discovery initial peers and 
multicast receive addresses via an environment variable or a file 
(in the current working directory) called NDDS_DISCOVERY_PEERS. 

You can run any number of publishers and subscribers programs, and can 
add and remove them dynamically from the domain.

Example:

To run the example application on domain <domain_id>:

On UNIX systems: 

objs/<arch>/test_publisher <domain_id> 
objs/<arch>/test_subscriber <domain_id> 

On Windows systems:

objs\<arch>\test_publisher <domain_id>  
objs\<arch>\test_subscriber <domain_id>   

*/
#include <algorithm>
#include <iostream>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
// Or simply include <dds/dds.hpp> 

#include "test.hpp"
#include "OpenSSL_ReaderWriter.h"


int subscriber_main(int domain_id, int sample_count)
{
  
    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant(domain_id);

    // Create a Topic -- and automatically register the type
    dds::topic::Topic<MyType> topic(participant, "Example MyType");

    // Create a DataReader with default Qos (Subscriber created in-line)
    dds::sub::DataReader<MyType> reader(dds::sub::Subscriber(participant), topic);

    // Create a ReadCondition for any data on this reader and associate a handler
    int count = 0;
    Crypto crypto;
    dds::sub::cond::ReadCondition read_condition(
        reader,
        dds::sub::status::DataState::any(),
        [&reader, &count, &crypto]()
    {
        // Take all samples
        dds::sub::LoanedSamples<MyType> samples = reader.take();
        for (auto sample : samples){
            if (sample.info().valid()){
                std::cout << "Cypher Text" << sample.data() << std::endl; 
		count = sample.data().ctr();
		auto ptext=crypto.decrypt(sample.data());
		std::cout << "Plain Text" << ptext << std::endl;
            }   
        }

    } // The LoanedSamples destructor returns the loan
    );

    // Create a WaitSet and attach the ReadCondition
    dds::core::cond::WaitSet waitset;
    waitset += read_condition;

    while (count < sample_count || sample_count == 0) {
        // Dispatch will call the handlers associated to the WaitSet conditions
        // when they activate

        waitset.dispatch(dds::core::Duration(4)); // Wait up to 4s each time
    }
    return 1;
}

int main(int argc, char *argv[])
{

    int domain_id = 0;
    int sample_count = 0; // infinite loop

    if (argc >= 2) {
        domain_id = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    // To turn on additional logging, include <rti/config/Logger.hpp> and
    // uncomment the following line:
    // rti::config::Logger::instance().verbosity(rti::config::Verbosity::STATUS_ALL);

    try {
        subscriber_main(domain_id, sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in subscriber_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}
