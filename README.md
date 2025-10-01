~ croissant

makes websites into lightweight, cross-platform desktop apps

<img src="screenshot.png"></img>
```
croissant https://example.com
```
> croissant is based on the operating system native webview

~ cli-arguments
| parameter | description                | status |
| :-------- | :------------------------- | :----- |
| --navigation | adds a simple forward, backward and reload button | under development |
| --frameless | removes the app titlebar completely | under development |

~ compile

1. clone repo
    ```
    git clone https://github.com/webview/webview.git
    ```
2. compile

    linux
    ```
    c++ main.cpp -Iwebview -std=c++11 `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0` -o croissant
    ```
    > you might need to install the dependencies: ```sudo apt-get install libgtk-3-dev libwebkit2gtk-4.0-dev```

    mac-os
    ```
    c++ main.cpp -Iwebview -std=c++11 -framework WebKit -o croissant
    ```

    windows
    ```
    c++ main.cpp -Iwebview -std=c++11 -mwindows -o croissant.exe
    ```
3. Run
    ```
    ./croissant https://github.com/manus-team
    ```
    > this will open a native webview window with the requested URL

create stuff.