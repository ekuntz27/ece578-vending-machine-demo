#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeveragePreferenceService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{
    class BeveragePreferenceServiceHandler : public BeveragePreferenceServiceIf {
        // Private class variables
        std::string hotBeverages [3] = {"cappuccino", "latte", "espresso"};
        std::string coldBeverages [3] = {"lemondate", "ice tea", "soda"};

        public:
        BeveragePreferenceServiceHandler();
        ~BeveragePreferenceServiceHandler() override=default;

        void GetBeverage(std::string& _return, const BeverageType::type btype) override;
    };

    // Constructor
    BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

    }

    void BeveragePreferenceServiceHandler::GetBeverage(std::string& _return, const BeverageType::type btype){
        printf("GetBeverage\n");
        if(btype == BeverageType::type::HOT){
            _return = hotBeverages[rand()%3];
        }else{
            _return = coldBeverages[rand()%3];
        }
    }
   

} // namespace vending_machine

#endif // VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H