# 📏 ccwc – Custom Word Count Tool

`ccwc` is a lightweight command-line utility written in C++ that mimics the functionality of the Unix `wc` (word count) tool. It counts **lines**, **words**, **bytes**, and **characters** from either a file or standard input.

---

## 🔧 Features

- ✅ Counts **lines**, **words**, **bytes**, and **UTF-8 characters**
- ✅ Supports both file input and piped/redirected input from `stdin`
- ✅ Custom implementation in C++ using standard libraries
- ✅ Handles multibyte UTF-8 characters correctly with `-m` option

---

## 📦 Usage

```bash
./ccwc [OPTION] [FILE]
