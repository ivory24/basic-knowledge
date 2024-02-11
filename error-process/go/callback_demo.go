package main

import (
	"errors"
	"fmt"
)

// 定义两个函数类型，作为成功和失败的回调
type SuccessCallback func(value string)
type FailureCallback func(err error)

// 模拟一个可能会失败的操作
func DoSomething(onSuccess SuccessCallback, onFailure FailureCallback) {
	// 假设这是一个可能会失败的操作
	result, err := operation()
	if err != nil {
		// 如果操作失败，调用失败回调
		onFailure(err)
	} else {
		// 如果操作成功，调用成功回调
		onSuccess(result)
	}
}

// 模拟一个可能会失败的操作
func operation() (string, error) {
	// 这里我们假设操作失败
	return "", errors.New("operation failed")
}

func main() {
	// 定义成功和失败的回调
	onSuccess := func(value string) {
		fmt.Println("Operation succeeded with value:", value)
	}
	onFailure := func(err error) {
		fmt.Println("Operation failed with error:", err)
	}

	// 执行操作
	DoSomething(onSuccess, onFailure)
}
