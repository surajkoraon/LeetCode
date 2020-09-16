class Solution
{
    public:
    struct Node
    {
        struct Node* zero=NULL;
        struct Node* one=NULL;
    };
    Node* root=new Node();
    void insert(int &num)
    {
        Node* head=root;
        for(int i=31;i>=0;i--)
        {
            if((num>>i)&1)
            {
                if(!head->one)
                {
                    head->one=new Node();
                }
                head=head->one;
            }
            else
            {
                if(!head->zero)
                {
                    head->zero=new Node();
                }
                head=head->zero;
            }
        }
    }
    int getMaxXOR(int &num)
    {
        Node* head=root;
        int temp=0;
        for(int i=31;i>=0;i--)
        {
            if((num>>i)&1)
            {
                if(head->zero)
                {
                    temp+=pow(2,i);
                    head=head->zero;
                }
                else
                {
                    head=head->one;
                }
            }
            else
            {
                if(head->one)
                {
                    temp+=pow(2,i);
                    head=head->one;
                }
                else
                {
                    head=head->zero;
                }
            }
        }
        return temp;
    }

    int findMaximumXOR(vector <int>&nums)
    {
        for(int i:nums)
        {
            insert(i);
        }
        int max=0;
        for(int i:nums) 
        {
        int temp=getMaxXOR(i);
        if(temp>max)max=temp;
        }
        return max;
    }
};
