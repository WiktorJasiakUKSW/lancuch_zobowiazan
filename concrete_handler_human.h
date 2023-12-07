#pragma once

#include <string>
#include "abstract_handler.h"

class HumanHandler : public AbstractHandler {
	std::string Handle(std::string request) override {
		if (request == "Cup of coffee"){
			return "Human: I'll drink a" + request + ". Cheers mate. \n";
		}
		else{
			return AbstractHandler::Handle(request);
		}
	}
};