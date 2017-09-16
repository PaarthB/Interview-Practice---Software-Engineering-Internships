void SortStack(struct Stack * orig_stack)
{
  struct Stack helper_stack;
  while (!IsEmpty(orig_stack))
  {
    int element = Pop(orig_stack);
    while (!IsEmpty(&helper_stack) && Top(&helper_stack) < element)
    {
      Push(orig_stack, Pop(&helper_stack));
    }
    Push(&helper_stack, element);
  }
  while (!IsEmpty(&helper_stack))
  {
    Push(orig_stack, Pop(&helper_stack));
  }
}