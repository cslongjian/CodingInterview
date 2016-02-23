import java.util.Arrays;


public class ArrayString {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("----------启动Java版本的编码----------");
		
		System.out.println("3.给定两个字符串，确定其中一个字符串重新排列后，是否可以变为另一个字符串不是变位词");
//	    这里有注意点：
//	    1，空格，大小写是否包含其中
//	    2，变位词，那么字符的长度是相等的。要作为优先判定条件之一
//	    3，可以先自行排序，后再进行比较。不过这个得基于有直接排序的语言，Java可以
//	    4，检查他们每个字符是否相等，用ascii去测试方案
		String str3_1 = "abcde";
		String str3_2 = "gdcba";
		
		ChekcSameString(str3_1, str3_2);
		
	}
	
	public static void ChekcSameString(String str1, String str2)
	{
		int length1 = str1.length();
		int length2 = str2.length();
//		char str11[] = str1.toCharArray();
	
		if(length1!=length2)
		{
			System.out.println("不是变位词，长度不等");
		}
		
		String s1[] = str1.split("");
		String s2[] = str2.split("");
		Arrays.sort(s1);
		Arrays.sort(s2);
		for(int i = 0; i < s1.length;i++)
		{
			System.out.print(s1[i]);
		}
		System.out.println();
		for(int i = 0; i < s2.length;i++)
		{
			System.out.print(s2[i]);
		}
		
		System.out.println();
		for(int i = 0; i < s1.length; i++)
		{
			if(s1[i].equals(s2[i]))
			{
				
			}else
			{
				System.out.println("不是变位词");
				return;
			}
		}
		
	}
}
