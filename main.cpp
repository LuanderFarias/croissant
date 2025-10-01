#include "webview.h"
#include <iostream>
#include <string>

// extract page title from URL.
// example: "https://github.com/luanderfarias" becomes "luanderfarias".
// implement new <title> scrapper in the future.
std::string get_title_from_url(const std::string& url ) {
    size_t start = url.find("://");
    if (start != std::string::npos) {
        start += 3; // Pula o "://"
    } else {
        start = 0;
    }

    size_t end = url.find("/", start);
    std::string domain = url.substr(start, end - start);

    // eemove "www."
    if (domain.rfind("www.", 0) == 0) {
        domain = domain.substr(4);
    }
    
    return domain;
}

int main(int argc, char* argv[]) {
    // --- args validation ---
    // check if user used one arg (URL).
    if (argc != 2) {
        std::cerr << "use: croissant <URL>" << std::endl;
        std::cerr << "example: croissant https://example.com" << std::endl;
        return 1;
    }

    std::string url = argv[1];
    // simple validation to ensure the URL starts with http:// or https://
    if (url.rfind("http://", 0 ) != 0 && url.rfind("https://", 0 ) != 0) {
        std::cerr << "error: the URL should start with 'http://' or 'https://'." << std::endl;
        return 1;
    }

    // --- Webview ---
    webview::webview w(true, nullptr ); // true = debug mode, can be changed to false

    // Define window title based on the URL.
    std::string title = get_title_from_url(url);
    w.set_title(title);

    // Define window size.
    w.set_size(1024, 768, WEBVIEW_HINT_NONE);

    // Define URL.
    w.navigate(url);

    // Executes main loop, keeping the window open.
    w.run();

    return 0;
}