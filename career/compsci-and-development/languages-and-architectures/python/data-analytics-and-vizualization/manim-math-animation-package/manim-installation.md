---
description: AI Generated Scrap
---

# Manim Installation

AI genearted scrap that'll be helpful iff you're installing with `uv` and Pycharm specifically. Told the agent to write it like a support ticket.&#x20;

### IT Ticket: Manim Environment Setup and Verification

**Issue Reported:**

User experienced significant difficulties setting up the Manim animation library on a Windows laptop. Initial attempts to install Manim using `pip` and `uv` resulted in a problematic environment where Manim's installation status was unclear (not listed by `pip list`, uninstallation commands failed). The project's `pyproject.toml` file was not configured for Manim, and the user was unsure how to proceed with a clean installation within the project's virtual environment (`.venv`). User also sought confirmation of a working setup.

**Resolution Steps Undertaken:**

1. **`pyproject.toml` Configuration:**
   * The primary configuration file for Python packaging, `pyproject.toml`, was updated to explicitly include `manim` as a project dependency.
   *   **Action:** Added `manim` to the `dependencies` list under the `[project]` section.

       ```
       [project]
       dependencies = [
           "manim",
       ]

       ```
   * This ensures that packaging tools like `uv` or `pip` know to install Manim when managing the project's environment.
2. **Virtual Environment Activation:**
   * User was guided to activate the project-specific Python virtual environment located in the `.venv` directory.
   *   **Action (PowerShell):**

       ```
       .\.venv\Scripts\Activate.ps1

       ```
   * This step isolates project dependencies and avoids conflicts with global Python packages.
3. **Dependency Installation with `uv`:**
   * With the virtual environment active and `pyproject.toml` configured, the `uv` tool was used to install the defined dependencies.
   *   **Action:**

       ```
       uv pip sync

       ```

       (Alternatively, `uv pip install -e .` could have been used for an editable install).
   * `uv` reads `pyproject.toml`, resolves dependencies, and installs them into the active `.venv`.
4. **LaTeX Prerequisite Check:**
   * User confirmed that LaTeX (a Manim dependency for text rendering) had been installed (e.g., MiKTeX or TeX Live).
   * **Guidance:** It was noted that for Manim to function correctly, the LaTeX distribution's `bin` directory needs to be in the system's PATH environment variable. A quick check (`latex -v` in a new terminal) was suggested to verify this.

**Testing and Verification:**

To confirm the successful setup and a functional Manim environment, the following steps were performed:

1. **Dependency Listing (Optional but Recommended):**
   * User could verify Manim's presence in the virtual environment.
   *   **Action:**

       ```
       uv pip list

       ```
   * This command lists all packages installed in the active environment; `manim` should appear.
2. **"Hello World" Test Scene:**
   * A basic Manim scene was created in the user's `app.py` file. This scene involved creating and animating simple text and a shape.
   *   **File:** `app.py`

       ```
       from manim import *

       class HelloWorld(Scene):
           def construct(self):
               text = Text("Hello, Manim!", font_size=72)
               circle = Circle()
               circle.set_fill(PINK, opacity=0.5)
               circle.next_to(text, DOWN, buff=0.5)
               self.play(Write(text))
               self.play(Create(circle))
               self.wait(2)
               self.play(FadeOut(text), FadeOut(circle))
               self.wait(1)

       ```
3. **Rendering the Test Scene:**
   * The Manim command-line interface was used to render the `HelloWorld` scene from `app.py`.
   *   **Action (in activated .venv):**

       ```
       manim -pql app.py HelloWorld
       ```

       * `-pql`: Preview (low quality) - renders the scene and opens the resulting video.
   * **Outcome:** The user confirmed that this command executed successfully, a video was generated and played, displaying the expected animation. This verified that Manim, its Python dependencies, and its LaTeX dependency were all correctly installed and configured.

**Additional Clarifications Provided:**

* **`uv` vs. `uvx`:** `uv` is the primary command-line tool. `uvx` was likely an experimental alias and `uv` should be used directly.
* **PATH for LaTeX:** Emphasized the importance of LaTeX being accessible via the system PATH for Manim to use it for text rendering.

**Current Status:** **RESOLVED**. The user's Manim environment is now correctly configured within the project's virtual environment, and a test animation was successfully rendered.
