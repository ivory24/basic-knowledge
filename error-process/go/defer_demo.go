package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

func main() {
	// 打开文件
	file, err := os.Open("demo.txt")
	if err != nil {
		log.Fatalf("Error opening file: %v", err)
	}
	defer file.Close()

	// 读取文件内容
	content, err := ioutil.ReadAll(file)
	if err != nil {
		log.Fatalf("Error reading file: %v", err)
	}

	// 打印文件内容
	fmt.Println("File content:")
	fmt.Println(string(content))
}

// go run main.go
