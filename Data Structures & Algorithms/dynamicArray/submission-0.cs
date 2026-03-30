public class DynamicArray 
{

    private int[] array;
    private int capacity;
    private int length;

    // Initialize the array and hold the capacity amount.
    public DynamicArray(int capacity) 
    {
        this.capacity = capacity;
        this.array = new int[this.capacity];
        this.length = 0;
    }

    // Get the element for at the current index.
    public int Get(int i) 
    {
        return array[i];
    }

    // Set the element at the current index.
    public void Set(int i, int n) 
    {
        array[i] = n;
    }

    // Push element n to the end of the array.
    public void PushBack(int n) 
    {
        if (length == capacity)
        {
            Resize();
        }

        array[length] = n;
        length++; 
    }

    // Pop the element at the end of the array.
    public int PopBack() 
    {
        if (length > 0)
        {
            // int poppedElement = array[length -  1];
            length--;
            // return poppedElement;
        }

        // We can just return length since length-- would just be the index of the last element.
        return array[length];
    }

    // Double the capacity of the array.
    private void Resize() 
    {
        capacity *= 2;
        int[] temp = new int[capacity];
        for (int i = 0; i < length; i++)
        {
            temp[i] = array[i];
        }

        array = temp;
    }

    // Return the number of elements within the array.
    public int GetSize() 
    {
        return length;
    }

    // Return the size(capacity) of the array.
    public int GetCapacity() 
    {
        return capacity;
    }
}
