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
#include <https_server_basic.h>


std::string callback(std::string A) {

	std::cout << "POST REQUEST  " << A << std::endl;
	https_client_request req("POST", "/1/messages.json");
	//https_client_request req("GET","/monitor/?line=14A&station=Keplerplatz&towards=Reumannplatz&countdown");
	json JS;
	//	dataframe hallo;
	//	hallo.write_file(A);

	JS["user"] = "u25eipbejdp986qk5cv6d2d9kt8x4d";
	JS["message"] = A;
	JS["token"] = "ahh7x5h32p2upqohfny3s5ndyqtw25";



	req.set_body(JS);
	//req.send_request("vtapi.floscodes.net","443");
	req.send_request("api.pushover.net", "443");
	return(A);
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
	start_https_server(func);

	return(4);
}
