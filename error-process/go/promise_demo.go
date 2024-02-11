package main

import (
	"fmt"
	"time"
)

// 模拟一个异步操作，返回一个通道，用于接收操作结果
func asyncOperation() chan interface{} {
	resultChan := make(chan interface{}, 1)

	go func() {
		// 模拟耗时操作
		time.Sleep(2 * time.Second)

		// 假设这是一个可能会失败的操作
		result, err := operation()
		if err != nil {
			resultChan <- err
		} else {
			resultChan <- result
		}
	}()

	return resultChan
}

// 模拟一个可能会失败的操作
func operation() (string, error) {
	// 这里我们假设操作成功
	return "Operation succeeded", nil
	//return "", errors.New("Operation failed") // 可以尝试将操作改为失败
}

func main() {
	// 执行异步操作
	promise := asyncOperation()

	// 等待异步操作的结果
	select {
	case result := <-promise:
		switch r := result.(type) {
		case string:
			fmt.Println("Success:", r)
		case error:
			fmt.Println("Error:", r)
		}
	case <-time.After(3 * time.Second): // 设置超时时间
		fmt.Println("Operation timed out")
	}
}
