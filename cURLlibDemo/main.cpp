// cURLlibDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include "../libcURL/include/curl.h"

#ifdef _DEBUG
#pragma comment(lib, "../libcURL/lib/libcurld.lib")
#else
#pragma comment(lib, "../libcURL/lib/libcurl.lib")
#endif

#include "kutfconv.h"

int main(void)
{
	CURL *curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (curl) {
		res = curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8081/login?username=ljm&pwd=111111");
		//res = curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
		//curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "username:ljm&pwd=111111");
		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
		std::cout << "\n";
		std::cout << "返回：" << res << std::endl;
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return 0;
}

