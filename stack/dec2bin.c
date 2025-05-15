void dec2bin(int n)
  int stack[MAX_STACK_SIZE];

  while(n > 0)
    push(n % 2);
    n = n / 2;
  }

  while(!is_empty)
    printf("%d", pop());
  }
  printf("\n");
}
