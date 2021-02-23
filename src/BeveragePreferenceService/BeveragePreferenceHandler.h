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

        std::string GetBeverage(BeverageType::type btype) override;
    };

    // Constructor
    BeveragePreferenceServiceHandler::BeveragePreferenceServiceHandler() {

    }

    std::string BeveragePreferenceServiceHandler::GetBeverage(BeverageType::type btype){
        printf("GetBeverage\n");
        if(btype == BeverageType::type::HOT){
            return hotBeverages[rand()%3];
        }else{
            return coldBeverages[rand()%3];
        }
    }
   

} // namespace vending_machine

#endif // VENDING_MACHINE_MICROSERVICES_BEVERAGEPREFERENCEHANDLER_H