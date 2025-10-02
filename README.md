~ croissant

turns websites into lightweight, cross-platform desktop apps using the native operating system webview with one command

<img src="screenshot.png"></img>
```
./croissant https://example.com
```

~ cli-arguments
| parameter | description                | status |
| :-------- | :------------------------- | :----- |
| --navigation | adds a simple forward, backward and reload button | under development |
| --frameless | removes the app titlebar completely | under development |

~ manual-usage
1. clone repo
    ```
    git clone https://github.com/luanderfarias/croissant
    ```
2. compile

    | os | command |
    | :--------------- | :------------------------- |
    | linux | ```c++ main.cpp -Iwebview -std=c++11 `pkg-config --cflags --libs gtk+-3.0 webkit2gtk-4.0` -o croissant``` |
    | warning | you might need to install the following dependencies: ```sudo apt-get install libgtk-3-dev libwebkit2gtk-4.0-dev``` depending on your linux distro |
    | mac-os | c++ main.cpp -Iwebview -std=c++11 -framework WebKit -o croissant |
    | windows | c++ main.cpp -Iwebview -std=c++11 -mwindows -o croissant.exe |
3. Run
    ```
    ./croissant https://example.com
    ```

create stuff.
