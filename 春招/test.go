package main

import (
	"fmt"
)

type test struct{
	x int8
	name string
}

func check(*t test,xx int8,names string){
	t.x = xx
	t.name = names
}
func main(){

}