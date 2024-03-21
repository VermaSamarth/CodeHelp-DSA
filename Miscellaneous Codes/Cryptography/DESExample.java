//Enter the secret text (in hexadecimal): 123456ABCD132536
//Enter the DES key (in hexadecimal): AABB09182736CCDD

import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import java.util.Base64;
import java.util.Scanner;

class DESExample {

    Cipher ecipher;
    Cipher dcipher;

    DESExample(SecretKey key) throws Exception {
        ecipher = Cipher.getInstance("DES");
        dcipher = Cipher.getInstance("DES");
        ecipher.init(Cipher.ENCRYPT_MODE, key);
        dcipher.init(Cipher.DECRYPT_MODE, key);
    }

    public String encrypt(String hexString) throws Exception {
        // Convert the hexadecimal string to bytes
        byte[] hexBytes = hexStringToByteArray(hexString);

        // Encrypt
        byte[] enc = ecipher.doFinal(hexBytes);

        // Convert bytes to hexadecimal to get a string
        return byteArrayToHexString(enc);
    }

    public String decrypt(String hexString) throws Exception {
        // Convert the hexadecimal string to bytes
        byte[] hexBytes = hexStringToByteArray(hexString);

        // Decrypt
        byte[] dec = dcipher.doFinal(hexBytes);

        // Convert bytes to hexadecimal to get a string
        return byteArrayToHexString(dec);
    }

    private static byte[] hexStringToByteArray(String s) {
        int len = s.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4)
                    + Character.digit(s.charAt(i + 1), 16));
        }
        return data;
    }

    private static String byteArrayToHexString(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : bytes) {
            hexString.append(String.format("%02X", b));
        }
        return hexString.toString();
    }

    public static void main(String[] argv) {
        try {
            Scanner scanner = new Scanner(System.in);

            System.out.print("Enter the secret text (in hexadecimal): ");
            String secretHex = scanner.nextLine();

            System.out.print("Enter the DES key (in hexadecimal): ");
            String keyHex = scanner.nextLine();

            // Convert the hexadecimal key to a SecretKey
            byte[] keyBytes = hexStringToByteArray(keyHex);
            SecretKey key = new javax.crypto.spec.SecretKeySpec(keyBytes, "DES");

            DESExample encrypter = new DESExample(key);
            String encrypted = encrypter.encrypt(secretHex);
            //System.out.println("Encrypted Value: " + encrypted);

            String Encrytext = encrypted;
            String first16Characters = Encrytext.substring(0, 16);
            System.out.println("Encrypted Value: " + first16Characters);

            String decrypted = encrypter.decrypt(encrypted);
            System.out.println("Decrypted: " + decrypted);

            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}