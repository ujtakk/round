package main

import (
  "fmt"
  "bufio"
  "os"
  "strconv"
)

const (
  SIZE = 10000
)

func main() {
  var buffer []float32

  src, err := os.Open("input.dat")
  if err != nil {
    fmt.Println("File read failed")
    os.Exit(1)
  }
  defer src.Close()

  s := bufio.NewScanner(src)
  for s.Scan() {
    val, _ := strconv.ParseFloat(s.Text(), 32)
    buffer = append(buffer, float32(val))
  }

  dst, err := os.Create("result_go.dat")
  if err != nil {
    fmt.Println("File write failed")
    os.Exit(1)
  }
  defer src.Close()

  fmt.Println(len(buffer))
  fmt.Println(buffer[SIZE-1])
  d := bufio.NewWriter(dst)
  for _, elem := range buffer {
    fmt.Fprintf(d, "%v\n", int16(elem*256.0))
    fmt.Fprintf(d, "%v\n", int16(elem/256.0))
  }
  d.Flush()
}
