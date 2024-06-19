//String plaintextHex = "00041214120412000C00131108231919";
//String cipherKeyHex = "2475A2B33475568831E2120013AA5487";
import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.util.Scanner;

public class AESExample {

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            // Get user input for plaintext
            System.out.print("Enter the plaintext (hexadecimal format): ");
            String plaintextHex = scanner.nextLine();

            // Get user input for cipher key
            System.out.print("Enter the cipher key (hexadecimal format): ");
            String cipherKeyHex = scanner.nextLine();

            // Convert hexadecimal strings to byte arrays
            byte[] plaintextBytes = hexStringToByteArray(plaintextHex);
            byte[] cipherKeyBytes = hexStringToByteArray(cipherKeyHex);

            // Convert byte arrays to SecretKey objects
            SecretKey secretKey = new SecretKeySpec(cipherKeyBytes, "AES");

            // Encrypt the plaintext
            String encryptedText = encrypt(plaintextBytes, secretKey);

            // Decrypt the ciphertext
            String decryptedText = decrypt(encryptedText, secretKey);

            // Print the results
            System.out.println("\nPlaintext:           " + plaintextHex);
            System.out.println("Cipher Key:          " + cipherKeyHex);
            System.out.println("Encrypted Ciphertext: " + encryptedText);
            System.out.println("Decrypted Plaintext: " + decryptedText);
            scanner.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static String encrypt(byte[] plaintextBytes, SecretKey secretKey) throws Exception {
        // Create a Cipher object and initialize it for encryption
        Cipher cipher = Cipher.getInstance("AES/ECB/NoPadding");  // Note: This example assumes no padding for simplicity
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);

        // Encrypt the bytes
        byte[] encryptedBytes = cipher.doFinal(plaintextBytes);

        // Encode the encrypted bytes to Hex for easier comparison
        return byteArrayToHexString(encryptedBytes);
    }

    private static String decrypt(String encryptedText, SecretKey secretKey) throws Exception {
        // Create a Cipher object and initialize it for decryption
        Cipher cipher = Cipher.getInstance("AES/ECB/NoPadding");  // Note: This example assumes no padding for simplicity
        cipher.init(Cipher.DECRYPT_MODE, secretKey);

        // Decode the Hex encoded encrypted text
        byte[] encryptedBytes = hexStringToByteArray(encryptedText);

        // Decrypt the bytes
        byte[] decryptedBytes = cipher.doFinal(encryptedBytes);

        // Convert the decrypted bytes to Hex for easier comparison
        return byteArrayToHexString(decryptedBytes);
    }

    private static byte[] hexStringToByteArray(String hexString) {
        int len = hexString.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(hexString.charAt(i), 16) << 4)
                    + Character.digit(hexString.charAt(i + 1), 16));
        }
        return data;
    }

    private static String byteArrayToHexString(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        for (byte aByte : bytes) {
            String hex = Integer.toHexString(0xFF & aByte);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }
        return hexString.toString().toUpperCase();
    }
}