# termiType

`termiType` is a terminal-based typing speed test built in C++. It displays a stream of words and tracks your typing accuracy, speed (WPM), and confidence — all within a classic ANSI-style terminal UI.
![Screenshot_20250529_133826](https://github.com/user-attachments/assets/ff79f2c7-f0d7-4c49-86b7-b9caba98b159)
![Screenshot_20250529_133908](https://github.com/user-attachments/assets/fed375e8-f0ba-4514-92bf-0f681a0bb0f1)



---

## Features

- Real-time typing feedback with color-coded accuracy
- Words-per-minute (WPM) and raw speed calculation
- Accuracy, error, and confidence display
- Simple TUI (Text User Interface) with box-style layout
- Supports backspace tracking for confidence metric
- Option to quit with `q` or `Esc`

---

## 🛠️ Build Instructions

Make sure you have a C++ compiler (like `g++`) installed. Then:

```bash
git clone git@github.com:SATYADAHAL/termiType.git
cd termiType
make
./tt
