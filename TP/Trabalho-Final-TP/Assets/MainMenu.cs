using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MainMenu : MonoBehaviour
{
    /**
     * Quando apertar o play ele vai carregar a proxima cena que esta
     * nas configurações de build do jogo; (para isso nos temos que adicionar a cena la na queue)
     */
    public void PlayGame()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
    }


    /*
     * Nao funciona durante o runtime dentro do editor
     * mas fora funciona (no caso se buildarmos o executavel) -> CONFIA!
     */
    public void QuitGame()
    {
        Debug.Log("SAIU DESSA PORRA DESSE JOGO!");
        Application.Quit();
    }
}
