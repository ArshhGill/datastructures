package linkedlist

import "fmt"

type Node[T comparable] struct{
    next *Node[T]
    prev *Node[T]
    val T
}


type Linked_list[T comparable] struct {
    head *Node[T]
    tail *Node[T]
    length int
}


func Uwu(){
    fmt.Println("more uwu")
}


func main() {
	fmt.Println("uwu")
}
