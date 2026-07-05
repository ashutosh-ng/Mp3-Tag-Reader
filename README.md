# 🎵 MP3 Tag Reader

A command-line based MP3 Tag Reader and Editor developed in **C** that allows users to view and edit metadata stored in MP3 files using the **ID3v2** tag format.

This project demonstrates concepts such as binary file handling, structures, pointers, modular programming, command-line argument processing, and file manipulation.

---

## 📌 Features

- View MP3 metadata
  - Title
  - Artist
  - Album
  - Year
  - Genre
  - Comment

- Edit MP3 metadata
  - Update Title
  - Update Artist
  - Update Album
  - Update Year
  - Update Genre
  - Update Comment

- Command-line interface
- Binary file processing
- Temporary file mechanism to safely update tags
- Modular code structure

---

## 🛠 Technologies Used

- C Programming
- GCC Compiler
- Standard C Library
- File Handling
- Structures
- Pointers
- Command Line Arguments
- Linux

---

## 📂 Project Structure

```
MP3_Tag_Reader/
│
├── main.c
├── edit.c
├── edit.h
├── README.md
└── sample.mp3
```

---

## ⚙️ Compilation

Compile the project using GCC:

```bash
gcc main.c edit.c -o mp3_tag_reader
```

---

## ▶️ Usage

### View MP3 Tags

```bash
./mp3_tag_reader -v sample.mp3
```

### Edit MP3 Tags

```bash
./mp3_tag_reader -e sample.mp3
```

---

## 📖 Sample Output

### View Metadata

```
Title   : My Song
Artist  : John Doe
Album   : Demo Album
Year    : 2025
Genre   : Pop
Comment : Sample MP3 File
```

### Edit Metadata

```
Select the field to edit

1. Title
2. Artist
3. Album
4. Year
5. Genre
6. Comment

Enter your choice: 1

Enter new title:
My New Song

Tag updated successfully.
```

---

## 💡 Concepts Demonstrated

- Binary File Handling
- ID3v2 Tag Parsing
- File Pointer Manipulation
- Big Endian Data Processing
- Structures
- Dynamic Memory Handling
- Modular Programming
- Command Line Utilities

---

## 📷 Workflow

```
MP3 File
     │
     ▼
Read ID3 Header
     │
     ▼
Extract Metadata
     │
     ├────────► Display Tags
     │
     ▼
Edit Selected Tag
     │
     ▼
Write Changes to Temporary File
     │
     ▼
Replace Original MP3
```

---

## 🚀 Future Improvements

- Support additional ID3v2 frames
- Display ID3 version information
- Display tag size
- Improve error handling
- Support batch editing
- Add UTF-16 metadata support
- Improve validation for corrupted MP3 files

---

## 👨‍💻 Author

**Ashutosh G**

Embedded Systems Enthusiast | Linux | Advanced C | C++ | Embedded Software Development

GitHub: https://github.com/<your-username>

LinkedIn: https://www.linkedin.com/in/ashutosh-gotgi/

---

## 📄 License

This project is intended for educational and learning purposes.
