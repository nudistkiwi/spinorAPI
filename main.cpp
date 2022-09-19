//
// Copyright (c) 2016-2017 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: HTTP SSL client, synchronous
//
//------------------------------------------------------------------------------


#include <ssl-client.h>
#include <httpserver_ssl.h>


std::string callback(std::string A) {

//https_client_request req("GET", "/monitor/?line=U6&station=Dresdner&countdown");
//req.send_request("vtapi.floscodes.net","80");
https_client_request req("GET", "/ogd_realtime/monitor?stopId=2957&stopId=318&stopId=4642&stopId=323&stopId=2951&stopId=4649");
req.send_request("www.wienerlinien.at","80");

//std::cout<<req.response_body()<<std::endl;

json input=json::parse(req.response_body());
//std::cout<<input["data"]["monitors"][4]["lines"][0]["departures"]["departure"][0]["departureTime"]["countdown"]<<std::endl;
std::cout<<"test"<<std::endl<<std::endl;

//std::cout<<input["data"]["monitors"][0]["lines"][0]["towards"]<<std::endl<<std::endl;
//std::cout<<input["data"]["monitors"][1].dump()<<std::endl<<std::endl;
//std::cout<<input["data"]["monitors"][6].dump()<<std::endl<<std::endl;
//std::cout<<input["data"]["monitors"][7].dump()<<std::endl<<std::endl;

std::cout<<"test2"<<std::endl<<std::endl;

int x=input["data"]["monitors"][5]["lines"][0]["departures"]["departure"][0]["departureTime"]["countdown"];
//int x2=input["data"]["monitors"][5]["lines"][0]["departures"]["departure"][0]["departureTime"]["countdown"];
//int x3=input["data"]["monitors"][5]["lines"][0]["departures"]["departure"][0]["departureTime"]["countdown"];
std::vector<int> time;
time.push_back(input["data"]["monitors"][1]["lines"][0]["departures"]["departure"][0]["departureTime"]["countdown"]);
time.push_back(input["data"]["monitors"][6]["lines"][0]["departures"]["departure"][0]["departureTime"]["countdown"]);
time.push_back(input["data"]["monitors"][7]["lines"][0]["departures"]["departure"][0]["departureTime"]["countdown"]);


std::vector<std::string> towards;

towards.push_back(input["data"]["monitors"][1]["lines"][0]["towards"]);
towards.push_back(input["data"]["monitors"][6]["lines"][0]["towards"]);
towards.push_back(input["data"]["monitors"][7]["lines"][0]["towards"]);

std::string message;
for(int i=0;i<towards.size();i++){

message+=std::to_string(time[i])+ " min "+towards[i]+"\n";


}

//["5"]["lines"]["0"]["depatures"]["depature"]["0"]
//auto vec=input["countdown"].get<std::vector<int>>();
//json input;
/*
input["data"]=req.response_body();
//auto vec=input["data"].get<std::vector<std::string>>();

try{



}

catch(...){}
*/

	std::cout << "POST REQUEST  " << A << std::endl;
	https_client_request req2("POST", "/1/messages.json");
	//https_client_request req("GET","/monitor/?line=14A&station=Keplerplatz&towards=Reumannplatz&countdown");
	json JS;
	//	dataframe hallo;
	//	hallo.write_file(A);

	JS["user"] = "u25eipbejdp986qk5cv6d2d9kt8x4d";
	JS["message"] = message;
	JS["token"] = "ahh7x5h32p2upqohfny3s5ndyqtw25";



	req2.set_body(JS);
	//req.send_request("vtapi.floscodes.net","443");
	req2.send_request("api.pushover.net", "443");

	
	return("index.html");
};



std::string callback2(std::string A) {

	std::cout << "GET REQUEST  " << A << std::endl;
	//if (A == ".\\test") {

	//}

	return(A);
};




int main() {




	std::function<std::string(std::string)> func = callback;
	//std::function<std::string(std::string)> func2 = callback2;

	//start_https_server(func, "8080");
	httpserver_ssl(func);


}
