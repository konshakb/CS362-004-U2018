

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


public UrlValidatorTest(String testName) {
super(testName);
}



public void testManualTest()
{
//You can use this function to implement your manual testing	
	
}


public void testYourFirstPartition()
{
	 //You can use this function to implement your First Partition testing	

}

public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	

}
//You need to create more test cases for your Partitions if you need to 

public void testIsValid()
{
	String[] goodSchemes = {
			"http://",
			"https://",
			"ftp://",
			"file://"
	};
	
	String[] badSchemes = {
			"://",
			"//",
			"/",
			"http:/",
			"http:",
			"http//"
	};
	
	String[] goodAuthorities = {
			"www.test.com",
			"test.com",
			"test.co",
			"test.org",
			"test.af",
			"1234.com",
			"user@test.com",
			"user:password@test.com",
			"0.0.0.0",
			"255.255.255.255",
			"[2001:db8:a0b:12f0::1]",
			"[FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF]",
			"[2001:db8::2:1]"
	};
	
	String[] badAuthorities = {
			"www. test .com",
			".www.test.com",
			"www.-test.com",
			"www.test-.com",
			"www.test",
			"com",
			"",
			"-1.-1.-1.-1",
			"256.256.256.256",
			"255.255.255.255.255",
			"255.255.255",
			"[255.255.255.255]",
			"[20010:db8:a0b:12f0::1]",
			"[2001::db8:a0b:12f0::1]",
			"[2001:db8:a0b:12f0:1:]",
			"[:2001:db8:a0b:12f0:1]",
			"[FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF]",
			"[FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF]",
			"[GGGG:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF]"
	};
	
	String[] goodPorts = {
			"",
			":80",
			":65535"
	};
	
	String[] badPorts = {
			":-1",
			"80",
			": 80",
			":80:",
			":65536"
	};
	
	String[] goodPaths = {
			"",
			"/",
			"/test",
			"/test.html",
			"/test/",
			"/test?test=test",
			"/test?test=test&test2=2",
			"/test?test=test&test",
			"/test#",
			"/test#test"
	};
	
	String[] badPaths = {
			"/..",
			"\\",
			"//",
			"/ test",
			"/test/?test=test test",
	 };
	
	UrlValidator validate = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	for (int i = 0; i < goodSchemes.length; i++) {
		if (!validate.isValid(goodSchemes[i] + "google.com")) {
			System.out.println("Good scheme failed: " + goodSchemes[i]);
		}
	}

	for (int i = 0; i < goodAuthorities.length; i++) {
		if (!validate.isValid("http://" + goodAuthorities[i])) {
			System.out.println("Good authority failed: " + goodAuthorities[i]);
		}
	}

	for (int i = 0; i < goodPorts.length; i++) {
		if (!validate.isValid("http://google.com" + goodPorts[i])) {
			System.out.println("Good port failed: " + goodPorts[i]);
		}
	}

	for (int i = 0; i < goodPaths.length; i++) {
		if (!validate.isValid("http://google.com" + goodPaths[i])) {
			System.out.println("Good path failed: " + goodPaths[i]);
		}
	}

	for (int i = 0; i < badSchemes.length; i++) {
		if (validate.isValid(badSchemes[i] + "google.com")) {
			System.out.println("Bad scheme passed: " + badSchemes[i]);
		}
	}

	for (int i = 0; i < badAuthorities.length; i++) {
		if (validate.isValid("http://" + badAuthorities[i])) {
			System.out.println("Bad authority passed: " + badAuthorities[i]);
		}
	}

	for (int i = 0; i < badPorts.length; i++) {
		if (validate.isValid("http://google.com" + badPorts[i])) {
			System.out.println("Bad port passed: " + badPorts[i]);
		}
	}

	for (int i = 0; i < badPaths.length; i++) {
		if (validate.isValid("http://google.com" + badPaths[i])) {
			System.out.println("Bad path passed: " + badPaths[i]);
		}
	}
}


	public static void main(String[] argv) {

		UrlValidatorTest fct = new UrlValidatorTest("url test");
		fct.testIsValid();
	}
}


